#include "inputwidget.h"
#include "ui_inputwidget.h"
#include "tabwidget.h"

InputWidget::InputWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InputWidget)
{
    ui->setupUi(this);

}

InputWidget::~InputWidget()
{
    delete ui;
}
