#include "turnwindow.h"
#include "ui_turnwindow.h"
#include "inputwidget.h"
#include "tabwidget.h"
#include "loadingwindow.h"
#include "moteurjeu.h"

#include <QPushButton>

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
    QPushButton *endTurnButton = new QPushButton("Fin du tour");

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
    // TODO: refresh les graphes
    tabWidget->redraw();
    // Refresh les inputs
    inputWidget->initialiser();
}


void TurnWindow::openLoadingWindow()
{
    // TODO: run le tour pour les IA et le joueur avec les paramètres entrés
    // TODO: Si c'est le dernier tour, on arrête le jeu et affiche le gagnant
    mLoadingWindow = new LoadingWindow();
    mLoadingWindow->show();


}

