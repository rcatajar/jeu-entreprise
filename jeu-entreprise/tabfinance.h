#ifndef TABFINANCE_H
#define TABFINANCE_H

#include <QWidget>

namespace Ui {
class TabFinance;
}

class TabFinance : public QWidget
{
    Q_OBJECT

public:
    explicit TabFinance(QWidget *parent = 0);
    ~TabFinance();

private:
    Ui::TabFinance *ui;
};

#endif // TABFINANCE_H
