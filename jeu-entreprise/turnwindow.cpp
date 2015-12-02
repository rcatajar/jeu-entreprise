#include "turnwindow.h"
#include "ui_turnwindow.h"

TurnWindow::TurnWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TurnWindow)
{
    ui->setupUi(this);
}

TurnWindow::~TurnWindow()
{
    delete ui;
}
