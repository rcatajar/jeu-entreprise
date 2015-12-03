#include "graphsrecherche.h"
#include "ui_graphsrecherche.h"

GraphsRecherche::GraphsRecherche(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphsRecherche)
{
    ui->setupUi(this);

    ajouterGraphInvestissementRecherche(ui->graph1);
    ajouterGraphQualiteVelos(ui->graph2);
}

GraphsRecherche::~GraphsRecherche()
{
    delete ui;
}

void GraphsRecherche::ajouterGraphInvestissementRecherche(QCustomPlot *customPlot)
{
    // Création de 2 barcharts vides :
    QCPBars *investissementCumule = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    QCPBars *investissementRecherche = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    customPlot->addPlottable(investissementCumule);
    customPlot->addPlottable(investissementRecherche);
    // Noms et couleurs :
    QPen pen;
    pen.setWidthF(1.2);
    investissementCumule->setName("Investissement Cumulé");
    pen.setColor(QColor(255, 131, 0));
    investissementCumule->setPen(pen);
    investissementCumule->setBrush(QColor(255, 131, 0, 50));
    investissementRecherche->setName("Investissement Recherche");
    pen.setColor(QColor(1, 92, 191));
    investissementRecherche->setPen(pen);
    investissementRecherche->setBrush(QColor(1, 92, 191, 50));

    // Préparation de l'axe X :
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;

    // Décalage des ticks pour mettre les barres côte à côte
    QVector<double> ticksGauche;
    ticksGauche = ticks;
    std::for_each(ticksGauche.begin(), ticksGauche.end(), [](double& d) { d-=0.2;});
    QVector<double> ticksDroite;
    ticksDroite = ticks;
    std::for_each(ticksDroite.begin(), ticksDroite.end(), [](double& d) { d+=0.2;});

    // Réglage de l'épaisseur des barres
    investissementCumule->setWidth(0.4);
    investissementRecherche->setWidth(0.4);

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
    customPlot->yAxis->setLabel("Investissement");
    customPlot->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    customPlot->yAxis->grid()->setSubGridPen(gridPen);

    // Ajout de données:
    // TODO : doit se mettre à jour à chaque tour
    QVector<double> investissementCumuleData, investissementRechercheData;
    investissementCumuleData   << 0.6*10.5 << 0.5*5.5 << 0.4*5.5 << 0.6*5.8 << 0.9*5.2 << 0.7*4.2 << 0.75*11.2;
    investissementRechercheData  << 0.86*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;
    investissementRecherche->setData(ticksDroite, investissementRechercheData);
    investissementCumule->setData(ticksGauche, investissementCumuleData);

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

void GraphsRecherche::ajouterGraphQualiteVelos(QCustomPlot *customPlot)
{

}
