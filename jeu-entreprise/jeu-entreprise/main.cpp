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
    int nb_entreprises = 2;
    float treso_initiale = 10000;
    float argent_initial = 500;
    int nb_objets_initials = rand() % nb_clients;

    // conteneurs pour les differents objets du jeu
    Entreprise *entreprises[nb_entreprises];
    Client *clients[nb_clients];
    vector <Objet> objets;  // on utilise un vecteur ici car le nombre d'objets n'est pas fixe

    vector <Objet*> objets_a_vendre;

    // Creation des entreprises
    for(int i = 0; i < nb_entreprises; i++){
        string nom = "Entreprise " + to_string(i + 1);
        entreprises[i] = new Entreprise(nom, treso_initiale);
    }

    // Creation des clients
    for(int i = 0; i < nb_clients; i++){
        string nom = "Client " + to_string(i + 1);
        clients[i] = new Client(nom, argent_initial);
    }

    // Creations des objets initiaux
    for(int i = 0; i < nb_objets_initials; i++){
        Objet objet = Objet(clients[i]);
        objets.push_back(objet);
        clients[i]->set_objet(&objet);
    }

    // Boucle principale
    while(tour < tour_max){
        tour ++;

        // Phase de Production. Chaque entreprise produit autant d'objet qu'elle veux
        for(int i = 0; i < nb_entreprises; i++){
            int n = i;  // FIXME: il faut le demander a l'utisateur et verifier qu'il est correct (< (treso - frais fixe) / frais variables)

            // l'entreprise produit, et retourne les objets produits
            vector <Objet> objets_produits = entreprises[i]->produire(n);
            // on les stocke dans notre vecteur d'objet
            objets.insert(objets.end(), objets_produits.begin(), objets_produits.end());
        }

        // Phase de Marketing. L'entreprise fixe son prix de vente
        for(int i = 0; i < nb_entreprises; i++){
            float prix_de_vente = 100;  // FIXME: le demander a l'utilisateur
            entreprises[i]->set_prix_de_vente(prix_de_vente);
        }

        // Phase de Vente.
        for(int i = 0; i < nb_clients; i++){
            if(clients[i]->get_objet() == 0){ // Si le client n'a pas d'objets (on pointe vers 0)

                objets_a_vendre = 0; // on réinitialise le marché

                for (int j = 0; j < nb_entreprises; j++){
                    objets_a_vendre.insert(objets_a_vendre.end(), entreprise[j].get_stock().begin(), entreprise[j].get_stock().end());
                }

                clients[i]->achat(objets_a_vendre); // va donner un objet au client

                if(client[i]->get_objet() != 0){ // si il a en effet acheté un objet
                    // on améliore la trésorerie de l'entreprise qui a fabriqué le produit qu'a acheté le client du prix de vente
                    *client[i]->get_objet().get_fabriquant().set_tresorerie(*client[i]->get_objet().get_fabriquant().get_tresorerie + *client[i]->get_objet().get_fabriquant().get_fabriquant());

                    // on retire l'objet acheté du stock de l'entreprise qui a fabriqué le produit
                    *client[i]->get_objet().get_fabriquant().delete_stock(*client[i]->get_objet());
                }

               }

        }

        // Phase de gestion des stocks
        for(auto objet = objets.begin(); objet != objets.end(); objet++){
            // objet->detruire
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
