#ifndef GRAPHSMARKETING_H
#define GRAPHSMARKETING_H

#include <QWidget>
#include "qcustomplot.h"

namespace Ui {
class GraphsMarketing;
}

class GraphsMarketing : public QWidget
{
    Q_OBJECT

public:
    explicit GraphsMarketing(QWidget *parent = 0);
    ~GraphsMarketing();

    void ajouterGraphPrixDesVelos(QCustomPlot *customPlot);
    void ajouterGraphNbVelosRestantsVendus(QCustomPlot *customPlot);

private:
    Ui::GraphsMarketing *ui;
};

#endif // GRAPHSMARKETING_H
