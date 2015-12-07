#include <QPushButton>

#include "turnwindow.h"
#include "ui_turnwindow.h"
#include "inputwidget.h"
#include "tabwidget.h"
#include "loadingwindow.h"
#include "moteurjeu.h"
#include "gameover.h"


TurnWindow::TurnWindow(QWidget *parent, MoteurJeu* _moteur) :
    QWidget(parent),
    ui(new Ui::TurnWindow)
{
    moteur = _moteur;
    ui->setupUi(this);

    QWidget* window = new QWidget;

    QVBoxLayout *layout = new QVBoxLayout;
    inputWidget = new InputWidget(0, moteur);
    tabWidget = new TabWidget(0, moteur);
    QPushButton *endTurnButton = new QPushButton("Fin du mois");

    // Insertion des widgets dans le VLayout
    layout->insertWidget(0, inputWidget);
    layout->insertWidget(1, tabWidget);
    layout->insertWidget(2, endTurnButton);

    window->setLayout(layout);
    window->show();

    connect(endTurnButton, SIGNAL(clicked()), this, SLOT(NextTurn()));

    ui->verticalPushed->addWidget(window);

}

TurnWindow::~TurnWindow()
{
    delete ui;
}

void TurnWindow::NextTurn()
{
    moteur->run_tour(inputWidget->get_production(), inputWidget->get_prix(), inputWidget->get_recherche());

    openLoadingWindow();
    // refresh les graphes
    tabWidget->redraw();
    // Refresh les inputs
    inputWidget->initialiser();
}


void TurnWindow::openLoadingWindow()
{
    int tresorerie = moteur->entreprises[0]->get_tresorerie();

    if (tresorerie > 0 && moteur->historique->tour < moteur->historique->tour_max)
    {
        mLoadingWindow = new LoadingWindow(0, moteur);
        mLoadingWindow->show();
    }
    else
    {
        this->close();
        mGameOver = new GameOver(0, moteur);
        mGameOver->show();
    }


}

