#include "tabfinance.h"
#include "ui_tabfinance.h"

TabFinance::TabFinance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabFinance)
{
    ui->setupUi(this);
}

TabFinance::~TabFinance()
{
    delete ui;
}
