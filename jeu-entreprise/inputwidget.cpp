#include "inputwidget.h"
#include "ui_inputwidget.h"
#include "tabwidget.h"

InputWidget::InputWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InputWidget)
{
    ui->setupUi(this);

//    setFixedSize(650, 190);

    mTabWidget = new TabWidget();
    mTabWidget->show();

}

InputWidget::~InputWidget()
{
    delete ui;
}
