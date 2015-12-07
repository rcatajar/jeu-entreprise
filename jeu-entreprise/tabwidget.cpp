#include <QTabWidget>
#include <QFileInfo>
#include <QDialogButtonBox>
#include <QVBoxLayout>

#include "tabwidget.h"
#include "ui_tabwidget.h"
#include "graphsproduction.h"
#include "graphsfinance.h"
#include "graphsrecherche.h"
#include "graphsmarketing.h"

#include "moteurjeu.h"


TabWidget::TabWidget(QWidget *parent, MoteurJeu* _moteur) :
    QDialog(parent),
    ui(new Ui::TabWidget)
{
    moteur = _moteur;
    ui->setupUi(this);

    tabWidget = new QTabWidget;
    tabWidget->addTab(new GraphsFinance(0, moteur), tr("Finance"));
    tabWidget->addTab(new GraphsProduction(0, moteur), tr("Production"));
    tabWidget->addTab(new GraphsRecherche(0, moteur), tr("Recherche"));
    tabWidget->addTab(new GraphsMarketing(0, moteur), tr("Marketing"));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    setLayout(mainLayout);
}

TabWidget::~TabWidget()
{
    delete ui;
}

void TabWidget::redraw(){
    // Redessine les graphes, a appeler a chaque début de tour

    // On vire les tabs actuels
    tabWidget->removeTab(0);
    tabWidget->removeTab(0);
    tabWidget->removeTab(0);
    tabWidget->removeTab(0);

    // On en crée des nouveaux
    tabWidget->addTab(new GraphsFinance(0, moteur), tr("Finance"));
    tabWidget->addTab(new GraphsProduction(0, moteur), tr("Production"));
    tabWidget->addTab(new GraphsRecherche(0, moteur), tr("Recherche"));
    tabWidget->addTab(new GraphsMarketing(0, moteur), tr("Marketing"));
}

