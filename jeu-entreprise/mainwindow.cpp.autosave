#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "turnwindow.h"

#include "inputwidget.h"

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
    delete temp;

}

void MainWindow::openTurnWindow()
{
    // TODO: Instancier un MoteurJeu avec les paramètres du form (nom entreprise + nb IA)
    mTurnWindow = new TurnWindow();
    mTurnWindow->show();

    temp = new InputWidget;
    temp->show();


}
