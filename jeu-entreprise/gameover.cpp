#include "gameover.h"
#include "ui_gameover.h"
#include "moteurjeu.h"
#include <numeric>

GameOver::GameOver(QWidget *parent, MoteurJeu* _moteur) :
    QWidget(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);

    moteur = _moteur;

    QVector<double> ventes = moteur->historique->get_vente();
    double sum_ventes = std::accumulate(ventes.begin(), ventes.end(), 0);

    QVector<double> qualite = moteur->historique->get_qualite_moyenne();
    double mean_qualite = std::accumulate(qualite.begin(), qualite.end(), 0) / qualite.size();

    ui->lcd_mois->display(moteur->historique->tour);
    ui->lcd_qualite->display(mean_qualite);
    ui->lcd_tresorerie->display(moteur->historique->get_tresorerie().back());
    ui->lcd_ventes->display(sum_ventes);
}

GameOver::~GameOver()
{
    delete ui;
}
