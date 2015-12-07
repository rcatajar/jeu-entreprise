#include "loadingwindow.h"
#include "ui_loadingwindow.h"

#include "moteurjeu.h"


LoadingWindow::LoadingWindow(QWidget *parent, MoteurJeu* _moteur) :
    QWidget(parent),
    ui(new Ui::LoadingWindow)
{
    ui->setupUi(this);

    moteur = _moteur;

    ui->lcd_mois->display(moteur->historique->tour);
    ui->lcd_qualite->display(moteur->historique->get_qualite_moyenne().back());
    ui->lcd_stock->display(moteur->historique->get_invendu().back());
    ui->lcd_tresorerie->display(moteur->historique->get_tresorerie().back());
    ui->lcd_ventes->display(moteur->historique->get_vente().back());
}

LoadingWindow::~LoadingWindow()
{
    delete ui;
}
