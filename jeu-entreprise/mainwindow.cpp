#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabdialog.h"

#include <QTabWidget>
#include <QWidget>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QPushButton startButton;
//    connect(startButton, SIGNAL(), )


    //    QWidget *centralWidget = new QWidget(window);
    //    QTabWidget *tabs = new QTabWidget(centralWidget);

    //    tabs->setFixedSize(245, 245);
    //    tabs->addTab(new QWidget(),"TAB 1");
    //    tabs->addTab(new QWidget(),"TAB 2");

    //    QFileInfo fileInfo(mainwindow);

    //    tabWidget = new QTabWidget;
    //    tabWidget->addTab(new GeneralTab(fileInfo), tr("General"));
    //    tabWidget->addTab(new PermissionsTab(fileInfo), tr("Permissions"));
    //    tabWidget->addTab(new ApplicationsTab(fileInfo), tr("Applications"));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete mTabDialog;
}

void MainWindow::openNewWindow()
{

   mTabDialog = new TabDialog("hey");
   mTabDialog->show();

}
