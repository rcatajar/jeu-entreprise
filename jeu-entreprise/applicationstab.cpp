#include "applicationstab.h"
#include "ui_applicationstab.h"

#include <QCheckBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>

ApplicationsTab::ApplicationsTab(const QFileInfo &fileInfo, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ApplicationsTab)
{
    ui->setupUi(this);

    QLabel *topLabel = new QLabel(tr("Open with:"));

    QListWidget *applicationsListBox = new QListWidget;
    QStringList applications;

    for (int i = 1; i <= 30; ++i)
        applications.append(tr("Application %1").arg(i));
    applicationsListBox->insertItems(0, applications);

    QCheckBox *alwaysCheckBox;

    if (fileInfo.suffix().isEmpty())
        alwaysCheckBox = new QCheckBox(tr("Always use this application to "
                                          "open this type of file"));
    else
        alwaysCheckBox = new QCheckBox(tr("Always use this application to "
                                          "open files with the extension '%1'").arg(fileInfo.suffix()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(topLabel);
    layout->addWidget(applicationsListBox);
    layout->addWidget(alwaysCheckBox);
    setLayout(layout);

}

ApplicationsTab::~ApplicationsTab()
{
    delete ui;
}
