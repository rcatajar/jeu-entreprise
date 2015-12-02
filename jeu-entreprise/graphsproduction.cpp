#include "graphsproduction.h"
#include "ui_graphsproduction.h"

GraphsProduction::GraphsProduction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphsProduction)
{
    ui->setupUi(this);
}

GraphsProduction::~GraphsProduction()
{
    delete ui;
}
