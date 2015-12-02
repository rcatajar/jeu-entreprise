#ifndef WIDGETINPUT_H
#define WIDGETINPUT_H

#include <QWidget>
#include <QTabWidget>

#include "tabdialog.h"

namespace Ui {
class WidgetInput;
}

class WidgetInput : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetInput(QWidget *parent = 0);
    ~WidgetInput();

private:
    Ui::WidgetInput *ui;
    QTabWidget *tabWidget;
    TabDialog *mTabDialog;
};

#endif // WIDGETINPUT_H
