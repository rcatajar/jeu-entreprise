// standard libraries
#include <vector>
#include <string>
#include <iostream>
#include <istream>
#include <sstream>

// Qt libs
#include <QApplication>

// la fenetre de jeu
#include "mainwindow.h"

// nos classes
#include "entreprise.h"
#include "client.h"
#include "objet.h"
#include "moteurjeu.h"

using namespace std;

int main(int argc, char *argv[])
{
    // QT old stuff
    // QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    // return a.exec();

    // Setup les variables de bases
    int tour_max = 10; // le nb de tour apres lesquels le jeu s'arrete
    int nb_clients = 5000;
    int nb_entreprises = 5;
    float treso_initiale = 10000;
    float argent_initial = 500;


    MoteurJeu moteur = MoteurJeu(nb_entreprises, treso_initiale, nb_clients, argent_initial, tour_max);

    // C'est parti !
    Entreprise* gagnant = moteur.run();

    // On affiche le gagnant
    cout << "Le gagnant est " << gagnant->get_nom();
    cout << " avec une tresorerie finale de " << gagnant->get_tresorerie() << endl;

    return 0;
}
