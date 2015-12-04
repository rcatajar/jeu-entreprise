#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "turnwindow.h"

#include <QTabWidget>
#include <QWidget>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete mTurnWindow;

}

void MainWindow::openTurnWindow()
{

    mTurnWindow = new TurnWindow();
    mTurnWindow->show();


}
