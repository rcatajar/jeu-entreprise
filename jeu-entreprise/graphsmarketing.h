#ifndef GRAPHSMARKETING_H
#define GRAPHSMARKETING_H

#include <QWidget>
#include "qcustomplot.h"

#include "moteurjeu.h"


namespace Ui {
class GraphsMarketing;
}

class GraphsMarketing : public QWidget
{
    Q_OBJECT

public:
    explicit GraphsMarketing(QWidget *parent = 0, MoteurJeu* moteur = NULL);
    ~GraphsMarketing();
    MoteurJeu* moteur;

    void ajouterGraphPrixDesVelos(QCustomPlot *customPlot);
    void ajouterGraphNbVelosRestantsVendus(QCustomPlot *customPlot);

private:
    Ui::GraphsMarketing *ui;
};

#endif // GRAPHSMARKETING_H
