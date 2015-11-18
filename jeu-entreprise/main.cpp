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

    // conteneurs pour les differents objets du jeu
    Entreprise *entreprises[nb_entreprises];
    Client *clients[nb_clients];
    vector<Objet> objets;  // on utilise un vecteur ici car le nombre d'objets n'est pas fixe

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

    // Boucle principale
    while(tour < tour_max){
        tour ++;

        // TODO
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
