#ifndef GRAPHSPRODUCTION_H
#define GRAPHSPRODUCTION_H

#include <QWidget>
#include "qcustomplot.h"

namespace Ui {
class GraphsProduction;
}

class GraphsProduction : public QWidget
{
    Q_OBJECT

public:
    explicit GraphsProduction(QWidget *parent = 0);
    ~GraphsProduction();

    void ajouterGraphNbVelosProduits(QCustomPlot *customPlot);
    void ajouterGraphNbVelosRestantsVendus(QCustomPlot *customPlot);

private:
    Ui::GraphsProduction *ui;
    double *m;


};

#endif // GRAPHSPRODUCTION_H
