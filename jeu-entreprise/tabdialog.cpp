#include "tabdialog.h"
#include "ui_tabdialog.h"

#include "generaltab.h"
#include "permissionstab.h"
#include "applicationstab.h"
#include "tabproduction.h"
#include "tabfinance.h"

#include <QTabWidget>
#include <QFileInfo>
#include <QDialogButtonBox>
#include <QVBoxLayout>

TabDialog::TabDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TabDialog)
{
    ui->setupUi(this);

    tabWidget = new QTabWidget;
    tabWidget->addTab(new TabFinance, tr("Finance"));
    tabWidget->addTab(new TabProduction, tr("Production"));

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                         | QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Tour 1"));
}

TabDialog::~TabDialog()
{
    delete ui;
}
