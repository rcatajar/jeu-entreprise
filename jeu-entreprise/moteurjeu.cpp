#include <vector>
#include <QString>
#include <math.h>
#include <limits>

#include "moteurjeu.h"
#include "entreprise.h"


using namespace std;

MoteurJeu::MoteurJeu(int nb_ia, int treso_initiale, int nb_clients, int argent_initial, int param_tour_max, QString nom)
{
    tour = 0;
    tour_max = param_tour_max;
    nom_joueur = nom;
    creation_entreprises_initiales(nb_ia, treso_initiale);
    creation_clients_initiaux(nb_clients, argent_initial);
    int nb_objets_initials = rand() % nb_clients;
    creation_objets_initiaux(nb_objets_initials);
    int cout_fixe = entreprises[0]->get_cout_fixe();
    int cout_variable = entreprises[0]->get_cout_variable();
    historique = new Historique(tour, tour_max, nom_joueur, nb_ia, nb_clients, cout_fixe, cout_variable);
    set_historique_intiale();
}

void MoteurJeu::creation_entreprises_initiales(int nb_ia, int treso_initiale){
    // On crée une entreprise controllé par le joueur
    entreprises.push_back((new Entreprise(nom_joueur, treso_initiale, false)));

    // Les entreprises restantes sont des IA
    for(int i = 0; i < nb_ia; i++){
        QString nom = "IA";
        entreprises.push_back(new Entreprise(nom, treso_initiale, true));
    }
}

void MoteurJeu::creation_clients_initiaux(int nb_clients, int argent_initial){
    for(int i = 0; i < nb_clients; i++){
        QString nom = "Client ";
        clients.push_back(new Client(nom, argent_initial));
    }
}

void MoteurJeu::creation_objets_initiaux(int nb_objets){
    for(int i = 0; i < nb_objets; i++){
        Objet* objet = new Objet(clients[i]);
        clients[i]->ajouter_au_stock(objet);
    }
}

void MoteurJeu::run_tour(int prod, int prix, int recherche){

    tour ++;

    historique->tour = tour;

    set_historique_stocks();

    phase_de_recherche(recherche);
    set_historique_recherche();

    phase_de_marketing(prix);
    set_historique_prix_de_vente();

    phase_de_production(prod);
    set_historique_productions();

    set_historique_qualite();

    set_historique_objets_en_vente();
    set_historique_acheteurs();

    phase_de_vente();
    set_historique_tresoreries();

    phase_de_gestion_des_stocks();
    phase_de_revenu();
}

Entreprise* MoteurJeu::get_gagnant(){
    int meilleur_tresorerie = 0;
    int idx_gagnant;
    for(int i = 0; i < entreprises.size(); i++){
        float treso = entreprises[i]->get_tresorerie();
        if(treso > meilleur_tresorerie){
            idx_gagnant = i;
            meilleur_tresorerie = treso;
        }
    }
    return entreprises[idx_gagnant];
}

void MoteurJeu::phase_de_production(int prod){

    for (int i = 0; i < entreprises.size(); i++){
        entreprises[i]->phase_de_production(prod);
    }
}

void MoteurJeu::phase_de_marketing(int prix){

    for (int i = 0; i < entreprises.size(); i++){
        entreprises[i]->phase_de_marketing(prix);
    }
}

void MoteurJeu::phase_de_recherche(int recherche){

    for (int i=0; i < entreprises.size(); i++){
        entreprises[i]->phase_de_recherche(recherche);
    }
}

vector <Objet*> MoteurJeu::get_objets_marche(){
        vector <Objet*> objets_en_vente;
        for(int i=0; i < entreprises.size(); i++){
            vector <Objet*> stock = entreprises[i]->get_stock();
            objets_en_vente.insert(objets_en_vente.end(), stock.begin(), stock.end());
        }
        return objets_en_vente;
}

void MoteurJeu::phase_de_vente(){

    // Permettra de calculer le nombre de vélo vendus
    vector <int> stock_precedent;


    for(int i=0; i < entreprises.size(); i++){
        stock_precedent.push_back(entreprises[i]->get_stock().size());
    }

    for (int i=0; i < clients.size(); i++){
        vector <Objet*> objets_en_vente = get_objets_marche();

        // Pour le moment, soit le client achete 0 objet, soit il en achete 1
        if(clients[i]->quantite_a_acheter() == 1){
            clients[i]->achat(objets_en_vente);
        }
    }

    // On affiche les achats et remplit l'historique
    vector <int> ventes;
    int achat = 0;



    for (int i=0; i <entreprises.size(); i++){

        int quantite_vendus = stock_precedent[i] - entreprises[i]->get_stock().size();

        ventes.push_back(quantite_vendus);
        achat += quantite_vendus;

    }
    historique->ventes.push_back(ventes);
    historique->objets_achetes.push_back(achat);
}

void MoteurJeu::phase_de_gestion_des_stocks(){

    int objets_detruits_clients = 0;
    vector <int> objets_detruits;
    for (int i=0; i < clients.size(); i++){
        int stock_avant_gestion = clients[i]->get_stock().size();
        clients[i]->gestion_des_stocks();
        int perte = clients[i]->get_stock().size() - stock_avant_gestion;
        objets_detruits_clients += perte;
    }

    historique->objets_detruits_client.push_back(objets_detruits_clients);

    for (int i=0; i < entreprises.size(); i++){
        int taille_stock_avant_gestion = entreprises[i]->get_stock().size();
        entreprises[i]->gestion_des_stocks();
        int taille_stock_apres_gestion = entreprises[i]->get_stock().size();
        objets_detruits.push_back(taille_stock_avant_gestion - taille_stock_apres_gestion);
    }

    historique->objets_detruits.push_back(objets_detruits);
}

void MoteurJeu::phase_de_revenu(){
    for(int i=0; i<clients.size(); i++){
        clients[i]->phase_de_revenu();
    }
}

void MoteurJeu::set_historique_intiale(){
    // On crée un vecteur de la taille du nombre d'entreprises, rempli de 0
    vector <int> zero_vector;
    for (int i=0; i < entreprises.size(); i++){
        zero_vector.push_back(0);
    }
    historique->prix_de_vente.push_back(zero_vector);
    historique->productions.push_back(zero_vector);
    historique->ventes.push_back(zero_vector);
    historique->objets_detruits.push_back(zero_vector);

    historique->objets_achetes.push_back(0);
    historique->objets_detruits_client.push_back(0);
    historique->prix_de_vente_moyen.push_back(0);

    set_historique_objets_en_vente();
    set_historique_stocks();
    set_historique_recherche();
    set_historique_tresoreries();
    set_historique_acheteurs();
    set_historique_qualite();
}

void MoteurJeu::set_historique_objets_en_vente(){
    int nb = get_objets_marche().size();
    historique->objets_en_vente.push_back(nb);
}

void MoteurJeu::set_historique_stocks(){
    vector <int> stocks;
    for (int i=0; i < entreprises.size(); i++){
        stocks.push_back(entreprises[i]->get_stock().size());
    }
    historique->stocks.push_back(stocks);
}

void MoteurJeu::set_historique_recherche(){
    vector <int> investissements;
    vector <int> qualite;
    for (int i = 0; i < entreprises.size(); i++){
        investissements.push_back(entreprises[i]->get_investissement_realise());
        qualite.push_back(entreprises[i]->get_qualite_marginale());
    }
    historique->investissements_recherche.push_back(investissements);
    historique->qualites_marginale.push_back(qualite);
}

void MoteurJeu::set_historique_tresoreries(){
    vector <int> tresos;
    for (int i = 0; i < entreprises.size(); i++){
        tresos.push_back(entreprises[i]->get_tresorerie());
    }
    historique->tresoreries.push_back(tresos);
}

void MoteurJeu::set_historique_acheteurs(){
    int acheteurs = 0;
    for (int i= 0; i < clients.size(); i++){
        if(clients[i]->quantite_a_acheter() > 0){
            acheteurs++;
        }
    }
    historique->nombre_acheteurs.push_back(acheteurs);
}

void MoteurJeu::set_historique_productions(){
    vector <int> production;
    vector <int> previous_stock = historique->stocks[tour];

    for(int i=0; i < entreprises.size(); i++){
        production.push_back(entreprises[i]->get_stock().size() - previous_stock[i]);
    }

    historique->productions.push_back(production);
}

void MoteurJeu::set_historique_prix_de_vente(){
    vector <int> prix_de_vente;
    int prix_moyen = 0;

    for (int i =0; i < entreprises.size(); i++){
        int prix = entreprises[i]->get_prix_de_vente();
        prix_de_vente.push_back(prix);
        prix_moyen += prix;
    }
    prix_moyen = prix_moyen / entreprises.size();
    historique->prix_de_vente_moyen.push_back(prix_moyen);
    historique->prix_de_vente.push_back(prix_de_vente);
}

void MoteurJeu::set_historique_qualite(){
    int qualite_moyenne = 0;
    int taille_stock = entreprises[0]->get_stock().size();

    if (taille_stock > 0){
        std::vector <Objet*> stock;
        stock = entreprises[0]->get_stock();

        for (int i =0; i < taille_stock; i++){
            qualite_moyenne += stock[i]->get_qualite();
        }
        qualite_moyenne = qualite_moyenne / taille_stock;
        historique->qualite.push_back(qualite_moyenne);


    }
    else{
        historique->qualite.push_back(0.);
    }
}

