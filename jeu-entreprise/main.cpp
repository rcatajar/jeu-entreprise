// standard libraries
#include <vector>
#include <string>
#include <iostream>

// Qt libs
#include <QApplication>

// la fenetre de jeu
#include "mainwindow.h"

// nos classes
#include "entreprise.h"
#include "client.h"
#include "objet.h"

using namespace std;

int main(int argc, char *argv[])
{
    // QT old stuff
    // QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    // return a.exec();

    // Setup les variables de bases
    int tour = 0;
    int tour_max = 10; // le nb de tour apres lesquels le jeu s'arrete
    int nb_clients = 10;
    int nb_entreprises = 3;
    float treso_initiale = 10000;
    float argent_initial = 500;
    int nb_objets_initials = rand() % nb_clients;

    // conteneurs pour les differents objets du jeu
    Entreprise *entreprises[nb_entreprises];
    Client *clients[nb_clients];

    // Creation des entreprises
    for(int i = 0; i < nb_entreprises; i++){
        string nom = "Entreprise " + to_string(i + 1);
        if(i<2){
            entreprises[i] = new Entreprise(nom, treso_initiale);
        } else {
            entreprises[i] = new Entreprise(nom, treso_initiale, 500, 10);
        }
    }

    // Creation des clients
    for(int i = 0; i < nb_clients; i++){
        string nom = "Client " + to_string(i + 1);
        clients[i] = new Client(nom, argent_initial);
    }

    // Creations des objets initiaux
    for(int i = 0; i < nb_objets_initials; i++){
        Objet* objet = new Objet(clients[i]);
        clients[i]->set_objet(objet);
    }

    // Boucle principale
    while(tour < tour_max){
        tour ++;

        // Phase de Production. Chaque entreprise produit autant d'objet qu'elle veux
        for(int i = 0; i < nb_entreprises; i++){
            int n = i;  // FIXME: il faut le demander a l'utisateur et verifier qu'il est correct (< (treso - frais fixe) / frais variables)
            entreprises[i]->produire(n);
        }

        // Phase de Marketing. L'entreprise fixe son prix de vente
        for(int i = 0; i < nb_entreprises; i++){
            float prix_de_vente = 100;  // FIXME: le demander a l'utilisateur
            entreprises[i]->set_prix_de_vente(prix_de_vente);
        }

        // Phase de Vente.

        for(int i = 0; i < nb_clients; i++){ // pour tous les clients

            // On récupère tous les objets en vente sur le marché
            // en concatenant le stock de de toutes les entreprises
            vector <Objet*> objets_en_vente;
            for(int i=0; i < nb_entreprises; i++){
                vector <Objet*> stock = entreprises[i]->get_stock();
                objets_en_vente.insert(objets_en_vente.end(), stock.begin(), stock.end());
            }

            if(clients[i]->get_objet() == NULL){ // check si le client n'a pas d'objet

                clients[i]->achat(objets_en_vente); // si il n'a pas d'objets
            }
        }

        // Phase de gestion des stocks
        for(int i = 0; i < nb_clients; i++){
            clients[i]->gestion_des_stocks();
        }
        for(int i=0; i < nb_entreprises; i++){
            entreprises[i]->gestion_des_stocks();
        }

    }

    // Determine le gagnant
    float meilleur_tresorerie = 0;
    int idx_gagnant;
    for(int i = 0; i < nb_entreprises; i++){
        float treso = entreprises[i]->get_tresorerie();
        if(treso > meilleur_tresorerie){
            idx_gagnant = i;
            meilleur_tresorerie = treso;
        }
    }

    // On affiche le gagnant
    cout << "Le gagnant est " << entreprises[idx_gagnant]->get_nom();
    cout << " avec une tresorerie finale de " << entreprises[idx_gagnant]->get_tresorerie() << endl;

    return 0;
}
