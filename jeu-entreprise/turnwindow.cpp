#include "turnwindow.h"
#include "ui_turnwindow.h"
#include "inputwidget.h"
#include "tabwidget.h"
#include "loadingwindow.h"

#include <QPushButton>

TurnWindow::TurnWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TurnWindow)
{
    ui->setupUi(this);

    QWidget* window = new QWidget;

    QVBoxLayout *layout = new QVBoxLayout;
    InputWidget *inputWidget = new InputWidget;
    TabWidget *tabWidget = new TabWidget;
    QPushButton *endTurnButton = new QPushButton("Fin du tour");

    layout->insertWidget(0, inputWidget);
    layout->insertWidget(2, tabWidget);
    layout->insertWidget(1, endTurnButton);

    window->setLayout(layout);
    window->show();

    connect(endTurnButton, SIGNAL(clicked()), this, SLOT(openNewWindow()));

    ui->verticalPushed->addWidget(window);

}

TurnWindow::~TurnWindow()
{
    delete ui;
}

void TurnWindow::openNewWindow()
{

    mLoadingWindow = new LoadingWindow();
    mLoadingWindow->show();


}

