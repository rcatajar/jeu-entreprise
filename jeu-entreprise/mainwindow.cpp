
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "turnwindow.h"

#include "inputwidget.h"

#include <QTabWidget>
#include <QWidget>
#include <QFileInfo>
#include <QString>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete mTurnWindow;

}

void MainWindow::openTurnWindow()
{
    int ias = ui->ia->value();
    QString nom = ui->nom->text();

    int tour_max = 10;
    int clients = 5000;
    int treso = 10000;
    int argent = 500;

    moteur = new MoteurJeu(ias, treso, clients, argent, tour_max, nom);
    mTurnWindow = new TurnWindow(0, moteur);
    mTurnWindow->show();

}
