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

    layout->insertWidget(0, inputWidget, 1);
    layout->insertWidget(1, tabWidget, 3);
    layout->insertWidget(2, endTurnButton, 1);

//    endTurnButton->sizePolicy().setVerticalStretch(1);
    layout->stretch(1);

    window->setLayout(layout);
    window->show();

    connect(endTurnButton, SIGNAL(clicked()), this, SLOT(openLoadingWindow()));

    ui->verticalPushed->addWidget(window);

}

TurnWindow::~TurnWindow()
{
    delete ui;
}

void TurnWindow::openLoadingWindow()
{
    // TODO: run le tour pour les IA et le joueur avec les paramètres entrés
    // TODO: Si c'est le dernier tour, on arrête le jeu et affiche le gagnant
    mLoadingWindow = new LoadingWindow();
    mLoadingWindow->show();


}

