#include "graphsfinance.h"
#include "ui_graphsfinance.h"

GraphsFinance::GraphsFinance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphsFinance)
{
    ui->setupUi(this);

    ajouterGraphTresoCA(ui->graph1);
    ajouterGraphRepartitionCouts(ui->graph2);

}

GraphsFinance::~GraphsFinance()
{
    delete ui;
}

void GraphsFinance::ajouterGraphTresoCA(QCustomPlot *customPlot)
{
    // Pour le barchart :
    // Création d'un barchart vide :
    QCPBars *CA = new QCPBars(customPlot->xAxis, customPlot->yAxis);

    customPlot->addPlottable(CA);

    // Création d'un deuxième graphe (classique)
    customPlot->addGraph(customPlot->xAxis, customPlot->yAxis2);
    customPlot->graph(0)->setName("Trésorerie");


    // Noms et couleurs barchart:
    QPen pen;
    pen.setWidthF(1.2);

    CA->setName("CA");
    pen.setColor(QColor(150, 222, 0));
    CA->setPen(pen);
    CA->setBrush(QColor(150, 222, 0, 70));

    // Noms et couleurs graph 0:
    QPen pen0;
    pen0.setWidthF(1.2);

//    pen0.setColor(QColor(255, 131, 0));
//    pen.setColor(QColor(150, 222, 0));
    pen0.setColor(QColor(1, 91, 191));
    customPlot->graph(0)->setPen(pen0);
    customPlot->graph(0)->setBrush(QColor(1, 92, 191, 50));

    // Préparation de l'axe X :
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;

    // TODO : labels doit représenter le nombre de tour passés
    labels << "Tour 1" << "Tour 2" << "Tour 3" << "Tour 4" << "Tour 5" << "Tour 6" << "Tour 7";
    customPlot->xAxis->setAutoTicks(false);
    customPlot->xAxis->setAutoTickLabels(false);
    customPlot->xAxis->setTickVector(ticks);
    customPlot->xAxis->setTickVectorLabels(labels);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTickCount(0);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->grid()->setVisible(true);
    // TODO : range doit évoluer avec nombre de tours passés
    customPlot->xAxis->setRange(0, 8);

    // Préparation de l'axe Y:
    // TODO : range doit évoluer automatiquement avec les données
    customPlot->yAxis->setRange(0, 12.1);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel("CA");
    customPlot->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    customPlot->yAxis->grid()->setSubGridPen(gridPen);

    // Ajout de données :
    QVector<double> CAData;
    // TODO : CAData doivent se MaJ à chaque tour
    CAData  << 0.86*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;
    CA->setData(ticks, CAData);

    // Pour le 2e graphe (plus classique) :
    // Ajout de données :
    QVector<double> TresoData;
    // TODO : TresoData doivent se MaJ à chaque tour
    TresoData << 1 << 2 << 5 << 3 << 7 << 2 << 6;

    // Traçage :
    customPlot->graph(0)->setData(ticks, TresoData);
    customPlot->yAxis2->setVisible(true);
    // TODO : range doit évoluer automatiquement avec les données
    customPlot->yAxis2->setRangeUpper(8);
    customPlot->yAxis2->setLabel("Trésorerie");


    // Setup de la légende:
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);
    customPlot->legend->setBrush(QColor(255, 255, 255, 200));
    QPen legendPen;
    legendPen.setColor(QColor(130, 130, 130, 200));
    customPlot->legend->setBorderPen(legendPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void GraphsFinance::ajouterGraphRepartitionCouts(QCustomPlot *customPlot)
{
    // Création de 3 barcharts vides :
    QCPBars *coutsFixes = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    QCPBars *coutsVariables = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    QCPBars *investissements = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    customPlot->addPlottable(coutsFixes);
    customPlot->addPlottable(coutsVariables);
    customPlot->addPlottable(investissements);
    // Noms et couleurs :
    QPen pen;
    pen.setWidthF(1.2);
    investissements->setName("Investissements");
    pen.setColor(QColor(255, 131, 0));
    investissements->setPen(pen);
    investissements->setBrush(QColor(255, 131, 0, 50));
    coutsVariables->setName("Coûts Variables");
    pen.setColor(QColor(1, 92, 191));
    coutsVariables->setPen(pen);
    coutsVariables->setBrush(QColor(1, 92, 191, 50));
    coutsFixes->setName("Coûts Fixes");
    pen.setColor(QColor(150, 222, 0));
    coutsFixes->setPen(pen);
    coutsFixes->setBrush(QColor(150, 222, 0, 70));
    // Ordre des barcharts :
    coutsVariables->moveAbove(coutsFixes);
    investissements->moveAbove(coutsVariables);

    // Préparation de l'axe X :
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
    // TODO : labels doit représenter le nombre de tour passés
    labels << "Tour 1" << "Tour 2" << "Tour 3" << "Tour 4" << "Tour 5" << "Tour 6" << "Tour 7";
    customPlot->xAxis->setAutoTicks(false);
    customPlot->xAxis->setAutoTickLabels(false);
    customPlot->xAxis->setTickVector(ticks);
    customPlot->xAxis->setTickVectorLabels(labels);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTickCount(0);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->grid()->setVisible(true);
    // TODO : range doit évoluer automatiquement avec les données
    customPlot->xAxis->setRange(0, 8);

    // Préparation de l'axe Y :
    // TODO : range doit évoluer automatiquement avec les données
    customPlot->yAxis->setRange(0, 12.1);
    customPlot->yAxis->setPadding(5);
    customPlot->yAxis->setLabel("Répartition des coûts");
    customPlot->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    customPlot->yAxis->grid()->setSubGridPen(gridPen);

    // Ajout de données:
    // TODO : doit se mettre à jour à chaque tour
    QVector<double> investissementsData, coutsVariablesData, coutsFixesData;
    coutsVariablesData  << 0.86*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;
    coutsFixesData << 0.08*10.5 << 0.12*5.5 << 0.12*5.5 << 0.40*5.8 << 0.09*5.2 << 0.00*4.2 << 0.07*11.2;
    investissementsData   << 0.06*10.5 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8 << 0.02*5.2 << 0.07*4.2 << 0.25*11.2;
    investissements->setData(ticks, investissementsData);
    coutsVariables->setData(ticks, coutsVariablesData);
    coutsFixes->setData(ticks, coutsFixesData);

    // Légende:
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    customPlot->legend->setBrush(QColor(255, 255, 255, 200));
    QPen legendPen;
    legendPen.setColor(QColor(130, 130, 130, 200));
    customPlot->legend->setBorderPen(legendPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
