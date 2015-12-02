#ifndef TABPRODUCTION_H
#define TABPRODUCTION_H

#include <QWidget>

namespace Ui {
class TabProduction;
}

class TabProduction : public QWidget
{
    Q_OBJECT

public:
    explicit TabProduction(QWidget *parent = 0);
    ~TabProduction();

private:
    Ui::TabProduction *ui;
};

#endif // TABPRODUCTION_H
