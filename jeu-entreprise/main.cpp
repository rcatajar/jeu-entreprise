// standard libraries
#include <vector>
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
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


//    MoteurJeu moteur = MoteurJeu(nb_ia, treso_initiale, nb_clients, argent_initial, tour_max, nom);

//    Entreprise* gagnant = moteur.run();
//    // C'est parti !

    return 0;
}
