#include <vector>
#include <string>
#include <iostream>
#include <istream>
#include <sstream>
#include <math.h>
#include<limits>

#include "moteurjeu.h"
#include "entreprise.h"

using namespace std;

MoteurJeu::MoteurJeu(int nb_entreprises, int treso_initiale, int nb_clients, int argent_initial, int param_tour_max)
{
    historique = new Historique();
    tour = 0;
    tour_max = param_tour_max;
    creation_entreprises_initiales(nb_entreprises, treso_initiale);
    creation_clients_initiaux(nb_clients, argent_initial);
    int nb_objets_initials = rand() % nb_clients;
    creation_objets_initiaux(nb_objets_initials);
}

void MoteurJeu::creation_entreprises_initiales(int nb_entreprises, int treso_initiale){
    // On crée une entreprise controllé par le joueur
    entreprises.push_back((new Entreprise("Joueur", treso_initiale, false)));

    // Les entreprises restantes sont des IA
    for(int i = 1; i < nb_entreprises; i++){
        string nom = "IA " + to_string(i);
        entreprises.push_back(new Entreprise(nom, treso_initiale, true));
    }
}

void MoteurJeu::creation_clients_initiaux(int nb_clients, int argent_initial){
    for(int i = 0; i < nb_clients; i++){
        string nom = "Client " + to_string(i + 1);
        clients.push_back(new Client(nom, argent_initial));
    }
}

void MoteurJeu::creation_objets_initiaux(int nb_objets){
    for(int i = 0; i < nb_objets; i++){
        Objet* objet = new Objet(clients[i]);
        clients[i]->ajouter_au_stock(objet);
    }
}

Entreprise* MoteurJeu::run(){
    while (tour < tour_max){
        run_tour();
    }
    return get_gagnant();

}

void MoteurJeu::run_tour(){
    tour ++;
    phase_de_recherche();
    phase_de_production();
    phase_de_marketing();
    phase_de_vente();
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

void MoteurJeu::phase_de_production(){
    cout << endl;
    cout << " ---------Phase de production -------------" << endl;
    cout << endl;

    for(int i = 0; i < entreprises.size(); i++){
        entreprises[i]->phase_de_production();
    }
}

void MoteurJeu::phase_de_marketing(){
    cout << endl;
    cout << " ---------Phase de marketing-------------" << endl;
    cout << endl;

    for (int i = 0; i < entreprises.size(); i++){
        entreprises[i]->phase_de_marketing();
    }


}

void MoteurJeu::phase_de_recherche(){
    for(int i=0; i < entreprises.size(); i++){
        entreprises[i]->phase_de_recherche();
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
    cout << endl;
    cout << " ---------Phase de vente -------------" << endl;
    cout << endl;

    // Permettra de calculer le nombre de vélo vendus
    int entreprises_tresorerie_precedente[entreprises.size()];

    for(int i=0; i < entreprises.size(); i++){
        entreprises_tresorerie_precedente[i] = entreprises[i]->get_tresorerie();
    }

    for (int i=0; i < clients.size(); i++){
        vector <Objet*> objets_en_vente = get_objets_marche();

        // Pour le moment, soit le client achete 0 objet, soit il en achete 1
        if(clients[i]->quantite_a_acheter() == 1){
            clients[i]->achat(objets_en_vente);
        }
    }

    // On affiche les achats
    for (int i=0; i <entreprises.size(); i++){

        int augmentation_treso = entreprises[i]->get_tresorerie()  - entreprises_tresorerie_precedente[i];
        int quantite_vendus = augmentation_treso / entreprises[i]->get_prix_de_vente();
        cout << entreprises[i]->get_nom() << " a augmenté sa trésorerie de : " << augmentation_treso;
        cout << " et a vendu : " << quantite_vendus << " vélos" << endl;
    }
}

void MoteurJeu::phase_de_gestion_des_stocks(){
    cout << endl;
    cout << " ---------Phase de gestion des stocks -------------" << endl;
    cout << endl;

    for (int i=0; i < clients.size(); i++){
        clients[i]->gestion_des_stocks();
    }
    for (int i=0; i < entreprises.size(); i++){
        int taille_stock_avant_gestion = entreprises[i]->get_stock().size();
        entreprises[i]->gestion_des_stocks();
        int taille_stock_apres_gestion = entreprises[i]->get_stock().size();
        cout << entreprises[i]->get_nom() << " a perdu ";
        cout << taille_stock_avant_gestion - taille_stock_apres_gestion;
        cout << " vélos dans son stock" << endl;
        cout << "Noveau stock: " << taille_stock_apres_gestion << " velos." << endl;
    }
}

void MoteurJeu::phase_de_revenu(){
    for(int i=0; i<clients.size(); i++){
        clients[i]->phase_de_revenu();
    }
}

