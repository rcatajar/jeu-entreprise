#include "inputwidget.h"
#include "ui_inputwidget.h"
#include "tabwidget.h"
#include "moteurjeu.h"


InputWidget::InputWidget(QWidget *parent, MoteurJeu* _moteur) :
    QWidget(parent),
    ui(new Ui::InputWidget)
{
    moteur = _moteur;

    ui->setupUi(this);

    connect(ui->sliderPrice, SIGNAL(valueChanged(int)), ui->lcdNumberPrice, SLOT(display(int)));
    connect(ui->sliderProd, SIGNAL(valueChanged(int)), ui->lcdNumberProd, SLOT(display(int)));
    connect(ui->sliderUseless, SIGNAL(valueChanged(int)), ui->lcdNumberUseless, SLOT(display(int)));

    prix_voulu = ui->sliderPrice->value();
    production_voulue = ui->sliderProd->value();
    recherche_voulue = ui->sliderUseless->value();


}

InputWidget::~InputWidget()
{
    delete ui;

}

int InputWidget::get_prix() const{
    return prix_voulu;
}

int InputWidget::get_production() const{
    return production_voulue;
}
int InputWidget::get_recherche() const{
    return recherche_voulue;
}
