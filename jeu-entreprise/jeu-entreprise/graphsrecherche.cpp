#include "graphsrecherche.h"
#include "ui_graphsrecherche.h"

GraphsRecherche::GraphsRecherche(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphsRecherche)
{
    ui->setupUi(this);
}

GraphsRecherche::~GraphsRecherche()
{
    delete ui;
}
