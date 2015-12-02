#include "widgetinput.h"
#include "ui_widgetinput.h"
#include "tabdialog.h"

WidgetInput::WidgetInput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetInput)
{
    ui->setupUi(this);

    mTabDialog = new TabDialog();
    mTabDialog->show();

}

WidgetInput::~WidgetInput()
{
    delete ui;
}
