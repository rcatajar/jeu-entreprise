#include "graphsfinance.h"
#include "ui_graphsfinance.h"

GraphsFinance::GraphsFinance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphsFinance)
{
    ui->setupUi(this);
}

GraphsFinance::~GraphsFinance()
{
    delete ui;
}
