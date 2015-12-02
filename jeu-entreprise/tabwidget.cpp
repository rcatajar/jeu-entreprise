#include "tabwidget.h"
#include "ui_tabwidget.h"

#include "graphsproduction.h"
#include "graphsfinance.h"
#include "graphsrecherche.h"
#include "graphsmarketing.h"

#include <QTabWidget>
#include <QFileInfo>
#include <QDialogButtonBox>
#include <QVBoxLayout>

TabWidget::TabWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TabWidget)
{
    ui->setupUi(this);

    tabWidget = new QTabWidget;
    tabWidget->addTab(new GraphsFinance, tr("Finance"));
    tabWidget->addTab(new GraphsProduction, tr("Production"));
    tabWidget->addTab(new GraphsRecherche, tr("Recherche"));
    tabWidget->addTab(new GraphsMarketing, tr("Marketing"));

//    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
//                                         | QDialogButtonBox::Cancel);

//    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
//    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

//    QVBoxLayout *mainLayout = new QVBoxLayout;
//    mainLayout->addWidget(tabWidget);
//    mainLayout->addWidget(buttonBox);
//    setLayout(mainLayout);

//    setWindowTitle(tr("Tour 1"));
}

TabWidget::~TabWidget()
{
    delete ui;
}
