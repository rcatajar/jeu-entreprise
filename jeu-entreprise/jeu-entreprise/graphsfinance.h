#ifndef GRAPHSFINANCE_H
#define GRAPHSFINANCE_H

#include <QWidget>

namespace Ui {
class GraphsFinance;
}

class GraphsFinance : public QWidget
{
    Q_OBJECT

public:
    explicit GraphsFinance(QWidget *parent = 0);
    ~GraphsFinance();

private:
    Ui::GraphsFinance *ui;
};

#endif // GRAPHSFINANCE_H
