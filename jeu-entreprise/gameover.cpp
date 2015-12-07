#include "gameover.h"
#include "ui_gameover.h"
#include "moteurjeu.h"

GameOver::GameOver(QWidget *parent, MoteurJeu* _moteur) :
    QWidget(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);

    moteur = _moteur;

    ui->lcd_mois->display(moteur->historique->tour);
    ui->lcd_qualite->display(moteur->historique->get_qualite_moyenne().back());
    ui->lcd_tresorerie->display(moteur->historique->get_tresorerie().back());
    ui->lcd_ventes->display(moteur->historique->get_vente().back());
}

GameOver::~GameOver()
{
    delete ui;
}
