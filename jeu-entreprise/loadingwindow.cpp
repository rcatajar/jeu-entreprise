#include "loadingwindow.h"
#include "ui_loadingwindow.h"
#include "moteurjeu.h"

LoadingWindow::LoadingWindow(QWidget *parent, MoteurJeu* _moteur) :
    QWidget(parent),
    ui(new Ui::LoadingWindow)
{
    ui->setupUi(this);

    moteur = _moteur;

    //ui->calculEnCours->setText(" Vous êtes au mois numero ", moteur->tour);




}

LoadingWindow::~LoadingWindow()
{
    delete ui;
}
