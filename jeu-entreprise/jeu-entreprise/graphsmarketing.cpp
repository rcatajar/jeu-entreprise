#include "graphsmarketing.h"
#include "ui_graphsmarketing.h"

GraphsMarketing::GraphsMarketing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphsMarketing)
{
    ui->setupUi(this);
}

GraphsMarketing::~GraphsMarketing()
{
    delete ui;
}
