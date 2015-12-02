#include "turnwindow.h"
#include "ui_turnwindow.h"

turnWindow::turnWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::turnWindow)
{
    ui->setupUi(this);
}

turnWindow::~turnWindow()
{
    delete ui;
}
