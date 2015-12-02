#include "tabproduction.h"
#include "ui_tabproduction.h"

TabProduction::TabProduction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabProduction)
{
    ui->setupUi(this);
}

TabProduction::~TabProduction()
{
    delete ui;
}
