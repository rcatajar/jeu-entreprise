#include "inputwidget.h"
#include "ui_inputwidget.h"
#include "tabwidget.h"
#include "moteurjeu.h"

#include <iostream>


InputWidget::InputWidget(QWidget *parent, MoteurJeu* _moteur) :
    QWidget(parent),
    ui(new Ui::InputWidget)
{
    moteur = _moteur;

    ui->setupUi(this);

    initialiser();

    connect(ui->sliderPrice, SIGNAL(valueChanged(int)), ui->lcdNumberPrice, SLOT(display(int)));
    connect(ui->sliderProd, SIGNAL(valueChanged(int)), ui->lcdNumberProd, SLOT(display(int)));
    connect(ui->sliderRecherche, SIGNAL(valueChanged(int)), ui->lcdNumberRecherche, SLOT(display(int)));

    connect(ui->sliderProd, SIGNAL(valueChanged(int)), this, SLOT(changement_production(int)));
    connect(ui->sliderRecherche, SIGNAL(valueChanged(int)), this, SLOT(changement_recherche(int)));

}

void InputWidget::changement_production(int production){

    int tresorerie;
    int CF;
    int CV;
    int tresorerie_restante;

    int recherche = ui->sliderRecherche->value();

    tresorerie = moteur->entreprises[0]->get_tresorerie();
    CF = moteur->entreprises[0]->get_cout_fixe();
    CV = moteur->entreprises[0]->get_cout_variable();

    tresorerie_restante = tresorerie - recherche - CF - CV * production;

    ui->progressBar->setValue(tresorerie_restante);
}

void InputWidget::changement_recherche(int recherche){

    int production_voulue = ui->sliderProd->value();

    int tresorerie;
    int CF;
    int CV;
    int tresorerie_restante;

    tresorerie = moteur->entreprises[0]->get_tresorerie();
    CF = moteur->entreprises[0]->get_cout_fixe();
    CV = moteur->entreprises[0]->get_cout_variable();

    tresorerie_restante = tresorerie - recherche - CF - CV * production_voulue;

    ui->progressBar->setValue(tresorerie_restante);
}

void InputWidget::initialiser(){

    int tresorerie = moteur->entreprises[0]->get_tresorerie();

    ui->progressBar->setRange(0, tresorerie);
    ui->progressBar->setValue(tresorerie);

    ui->sliderPrice->setRange(0,500);
    ui->sliderProd->setRange(0,(tresorerie - moteur->entreprises[0]->get_cout_fixe())/moteur->entreprises[0]->get_cout_variable());
    ui->sliderRecherche->setRange(0,tresorerie);

    ui->sliderPrice->setValue(0);
    ui->sliderRecherche->setValue(0);
    ui->sliderProd->setValue(0);

}


InputWidget::~InputWidget()
{
    delete ui;

}

int InputWidget::get_prix() const{
    return ui->sliderPrice->value();
}

int InputWidget::get_production() const{
    return ui->sliderProd->value();
}
int InputWidget::get_recherche() const{
    return ui->sliderRecherche->value();
}
