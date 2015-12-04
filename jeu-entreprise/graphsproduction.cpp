#include "graphsproduction.h"
#include "ui_graphsproduction.h"

GraphsProduction::GraphsProduction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphsProduction)
{
    ui->setupUi(this);

    ajouterGraphNbVelosProduits(ui->graph1);
    ajouterGraphNbVelosRestantsVendus(ui->graph2);
}

GraphsProduction::~GraphsProduction()
{
    delete ui;
}

void GraphsProduction::ajouterGraphNbVelosProduits(QCustomPlot *customPlot)
{
    // Création de 3 barcharts vides :
    // TODO : relier au nombre d'entreprises
    QCPBars *entreprise1 = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    QCPBars *entreprise2 = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    QCPBars *entreprise3 = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    customPlot->addPlottable(entreprise1);
    customPlot->addPlottable(entreprise2);
    customPlot->addPlottable(entreprise3);
    // Noms et couleurs :
    QPen pen;
    pen.setWidthF(1.2);
    entreprise3->setName("Entreprise 1");
    pen.setColor(QColor(255, 131, 0));
    entreprise3->setPen(pen);
    entreprise3->setBrush(QColor(255, 131, 0, 50));
    entreprise2->setName("Entreprise 2");
    pen.setColor(QColor(1, 92, 191));
    entreprise2->setPen(pen);
    entreprise2->setBrush(QColor(1, 92, 191, 50));
    entreprise1->setName("Entreprise 3");
    pen.setColor(QColor(150, 222, 0));
    entreprise1->setPen(pen);
    entreprise1->setBrush(QColor(150, 222, 0, 70));

    // TODO : Ajouter ces couleurs pour les autres entreprises :
    // QColor(25, 142, 67);
    // QColor(167, 10, 242);

    // Préparation de l'axe X :
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;

    // TODO : relier "n" au nombre d'entreprises
    int n = 3;
    double m;
    m = 0.9 / n;

    // Décalage des ticks pour mettre les barres côte à côte
    // TODO : un vector de ticks de taille "n"
    QVector<double> ticksGauche;
    ticksGauche = ticks;
    std::for_each(ticksGauche.begin(), ticksGauche.end(), [&m](double& d) { d-=m;});
    QVector<double> ticksDroite;
    ticksDroite = ticks;
    std::for_each(ticksDroite.begin(), ticksDroite.end(), [&m](double& d) { d+=m;});

    // Réglage de l'épaisseur des barres
    // TODO : un vecteur "entreprise" ?
    entreprise1->setWidth(m);
    entreprise2->setWidth(m);
    entreprise3->setWidth(m);

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
    customPlot->yAxis->setLabel("Nb vélos produits");
    customPlot->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    customPlot->yAxis->grid()->setSubGridPen(gridPen);

    // Ajout de données:
    // TODO : doit se mettre à jour à chaque tour
    QVector<double> entreprise3Data, entreprise2Data, entreprise1Data;
    entreprise3Data   << 0.6*10.5 << 0.5*5.5 << 0.4*5.5 << 0.6*5.8 << 0.9*5.2 << 0.7*4.2 << 0.75*11.2;
    entreprise2Data  << 0.86*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;
    entreprise1Data << 0.8*10.5 << 1.2*5.5 << 1.2*5.5 << 0.90*5.8 << 0.9*5.2 << 0.70*4.2 << 0.5*11.2;
    entreprise3->setData(ticksDroite, entreprise3Data);
    entreprise2->setData(ticks, entreprise2Data);
    entreprise1->setData(ticksGauche, entreprise1Data);

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

void GraphsProduction::ajouterGraphNbVelosRestantsVendus(QCustomPlot *customPlot)
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
    customPlot->xAxis->setRange(0, 8);

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
