#ifndef GRAPHSRECHERCHE_H
#define GRAPHSRECHERCHE_H

#include <QWidget>
#include "qcustomplot.h"

namespace Ui {
class GraphsRecherche;
}

class GraphsRecherche : public QWidget
{
    Q_OBJECT

public:
    explicit GraphsRecherche(QWidget *parent = 0);
    ~GraphsRecherche();

    void ajouterGraphInvestissementRecherche(QCustomPlot *customPlot);
    void ajouterGraphQualiteVelos(QCustomPlot *customPlot);

private:
    Ui::GraphsRecherche *ui;
};

#endif // GRAPHSRECHERCHE_H
