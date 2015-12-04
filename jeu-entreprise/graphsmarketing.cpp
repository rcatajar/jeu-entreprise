#include "graphsmarketing.h"
#include "ui_graphsmarketing.h"

GraphsMarketing::GraphsMarketing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphsMarketing)
{
    ui->setupUi(this);

    ajouterGraphPrixDesVelos(ui->graph1);
    ajouterGraphNbVelosRestantsVendus(ui->graph2);
}

GraphsMarketing::~GraphsMarketing()
{
    delete ui;
}

void GraphsMarketing::ajouterGraphPrixDesVelos(QCustomPlot *customPlot)
{
    // Création d'un premier graphe (classique)
    customPlot->addGraph(customPlot->xAxis, customPlot->yAxis);
    customPlot->graph(0)->setName("Entreprise 1");
    // Création d'un deuxième graphe (classique)
    customPlot->addGraph(customPlot->xAxis, customPlot->yAxis);
    customPlot->graph(1)->setName("Entreprise 2");
    // Création d'un deuxième graphe (classique)
    customPlot->addGraph(customPlot->xAxis, customPlot->yAxis);
    customPlot->graph(2)->setName("Entreprise 3");

    // Noms et couleurs graph 0:
    QPen pen0;
    pen0.setWidthF(1.2);

    pen0.setColor(QColor(1, 92, 191));
    customPlot->graph(0)->setPen(pen0);
    customPlot->graph(0)->setBrush(QColor(1, 92, 191, 30));

    // Noms et couleurs graph 1:
    QPen pen1;
    pen1.setWidthF(1.2);

    pen1.setColor(QColor(150, 222, 0));
    customPlot->graph(1)->setPen(pen1);
    customPlot->graph(1)->setBrush(QColor(150, 222, 0, 70));

    // Noms et couleurs graph 2:
    QPen pen2;
    pen2.setWidthF(1.2);

    pen2.setColor(QColor(255, 131, 0));
    customPlot->graph(2)->setPen(pen2);
    customPlot->graph(2)->setBrush(QColor(255, 131, 0, 30));

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
    customPlot->xAxis->setRange(0.5, 7.5);

    // Préparation de l'axe Y:
    // TODO : range doit évoluer automatiquement avec les données
    customPlot->yAxis->setRange(0, 200);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel("Nb de vélos vendus");
    customPlot->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    customPlot->yAxis->grid()->setSubGridPen(gridPen);

    // Pour le 1er graphe :
    // Ajout de données :
    QVector<double> Entreprise1Data;
    // TODO : TresoData doivent se MaJ à chaque tour
    Entreprise1Data << 100 << 120 << 170 << 80 << 145 << 95 << 138;

    // Pour le 2e graphe :
    // Ajout de données :
    QVector<double> Entreprise2Data;
    // TODO : TresoData doivent se MaJ à chaque tour
    Entreprise2Data << 20 << 80 << 40 << 100 << 48 << 78 << 100;


    // Pour le 3e graphe :
    // Ajout de données :
    QVector<double> Entreprise3Data;
    // TODO : TresoData doivent se MaJ à chaque tour
    Entreprise3Data << 120 << 100 << 80 << 140 << 30 << 28 << 150;

    // Traçage :
    customPlot->graph(0)->setData(ticks, Entreprise1Data);
    customPlot->graph(1)->setData(ticks, Entreprise2Data);
    customPlot->graph(2)->setData(ticks, Entreprise3Data);

    // Setup de la légende:
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);
    customPlot->legend->setBrush(QColor(255, 255, 255, 200));
    QPen legendPen;
    legendPen.setColor(QColor(130, 130, 130, 200));
    customPlot->legend->setBorderPen(legendPen);
    QFont legendFont = font();
    legendFont.setPointSize(7);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}

void GraphsMarketing::ajouterGraphNbVelosRestantsVendus(QCustomPlot *customPlot)
{
    // Création d'un premier graphe (classique)
    customPlot->addGraph(customPlot->xAxis, customPlot->yAxis);
    customPlot->graph(0)->setName("Nb vélos vendus");
    // Création d'un deuxième graphe (classique)
    customPlot->addGraph(customPlot->xAxis, customPlot->yAxis);
    customPlot->graph(1)->setName("Nb vélos restants");

    // Noms et couleurs graph 0:
    QPen pen0;
    pen0.setWidthF(1.2);

    pen0.setColor(QColor(1, 92, 191));
    customPlot->graph(0)->setPen(pen0);
    customPlot->graph(0)->setBrush(QColor(1, 92, 191, 50));

    // Noms et couleurs graph 1:
    QPen pen1;
    pen1.setWidthF(1.2);

    pen1.setColor(QColor(150, 222, 0));
    customPlot->graph(1)->setPen(pen1);
    customPlot->graph(1)->setBrush(QColor(150, 222, 0, 70));

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
    customPlot->xAxis->setRange(0.5, 7.5);

    // Préparation de l'axe Y:
    // TODO : range doit évoluer automatiquement avec les données
    customPlot->yAxis->setRange(0, 200);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel("Nb de vélos");
    customPlot->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    customPlot->yAxis->grid()->setSubGridPen(gridPen);

    // Pour le 1er graphe :
    // Ajout de données :
    QVector<double> VendusData;
    // TODO : TresoData doivent se MaJ à chaque tour
    VendusData << 100 << 120 << 170 << 80 << 145 << 95 << 138;

    // Pour le 2e graphe :
    // Ajout de données :
    QVector<double> RestantsData;
    // TODO : TresoData doivent se MaJ à chaque tour
    RestantsData << 20 << 80 << 40 << 100 << 48 << 78 << 100;

    // Traçage :
    customPlot->graph(0)->setData(ticks, VendusData);
    customPlot->graph(1)->setData(ticks, RestantsData);

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

