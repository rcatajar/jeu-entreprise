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

//    setFixedSize(300, 800);

    QWidget* window = new QWidget;

    QVBoxLayout *layout = new QVBoxLayout;
    InputWidget *inputWidget = new InputWidget;
    TabWidget *tabWidget = new TabWidget;
    QPushButton *endTurnButton = new QPushButton("Fin du tour");
    QPushButton *button2 = new QPushButton("Bouton 2");
    QPushButton *button3 = new QPushButton("Bouton 3");

    // Dimensionnent des widgets
//    inputWidget->

    // Insertion des widgets dans le VLayout
    layout->insertWidget(0, inputWidget);
    layout->insertWidget(1, tabWidget);
    layout->insertWidget(2, endTurnButton);
//    layout->insertWidget(0, endTurnButton);
//    layout->insertWidget(1, button2);
//    layout->insertWidget(2, button3);

//    endTurnButton->sizePolicy().setVerticalStretch(1);
//    layout->setStretch(0,1);
//    layout->setStretch(1,2);
//    layout->setStretch(2,1);

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

