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
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
