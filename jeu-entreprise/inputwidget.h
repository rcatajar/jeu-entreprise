/* Widget rassemblant tous les inputs du jouer lors d'un tour
 * Appelée par : TurnWindow */

#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QWidget>
#include <QTabWidget>

#include "tabwidget.h"

namespace Ui {
class InputWidget;
}

class InputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InputWidget(QWidget *parent = 0);
    ~InputWidget();

private:
    Ui::InputWidget *ui;
    QTabWidget *tabWidget;
    TabWidget *mTabWidget;
};

#endif // INPUTWIDGET_H
