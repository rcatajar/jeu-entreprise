#ifndef GRAPHSFINANCE_H
#define GRAPHSFINANCE_H

#include <QWidget>
#include "qcustomplot.h"
#include "moteurjeu.h"

namespace Ui {
class GraphsFinance;
}

class GraphsFinance : public QWidget
{
    Q_OBJECT

public:
    explicit GraphsFinance(QWidget *parent = 0, MoteurJeu* moteur = NULL);
    MoteurJeu* moteur;
    ~GraphsFinance();

    void ajouterGraphTresoCA(QCustomPlot *customPlot);
    void ajouterGraphRepartitionCouts(QCustomPlot *customPlot);

private:
    Ui::GraphsFinance *ui;
};

#endif // GRAPHSFINANCE_H
