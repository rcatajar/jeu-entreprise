#include "graphsrecherche.h"
#include "ui_graphsrecherche.h"

#include "moteurjeu.h"


GraphsRecherche::GraphsRecherche(QWidget *parent, MoteurJeu* _moteur) :
    QWidget(parent),
    ui(new Ui::GraphsRecherche)
{
    moteur = _moteur;
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
    QVector<double> ticks = moteur->historique->get_ticks();
    QVector<QString> labels = moteur->historique->get_labels();
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
    customPlot->xAxis->setRange(0.5, moteur->historique->tour + 0.5);

    // Préparation de l'axe Y :
    // TODO : range doit évoluer automatiquement avec les données
    customPlot->yAxis->setRange(0, moteur->historique->get_investissement_max() + 100.) ;
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
    investissementCumule->setData(ticks, moteur->historique->get_investissement_cumule());
    investissementRecherche->setData(ticks, moteur->historique->get_investissement());

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
    // Création d'un premier graphe (classique)
    customPlot->addGraph(customPlot->xAxis, customPlot->yAxis);
    customPlot->graph(0)->setName("Qualité des vélos");
    // Création d'un deuxième graphe (erreurs)
    customPlot->addGraph(customPlot->xAxis, customPlot->yAxis);
    customPlot->graph(1)->setName("Qualité du stock");
    customPlot->graph(1)->setPen(QPen(Qt::blue));
    customPlot->graph(1)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCross, QPen(QColor(255,131,0)), QBrush(QColor(255, 131, 0, 20)), 5));
    customPlot->graph(1)->setErrorType(QCPGraph::etValue);
    customPlot->graph(1)->setErrorPen(QPen(QColor(255,131,0)));

    // Noms et couleurs graph 0:
    QPen pen0;
    pen0.setWidthF(1.2);

    pen0.setColor(QColor(1, 92, 191));
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
    customPlot->xAxis->setRange(0.5, 7.5);

    // Préparation de l'axe Y:
    // TODO : range doit évoluer automatiquement avec les données
    customPlot->yAxis->setRange(0, 200);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel("Qualité des vélos");
    customPlot->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    customPlot->yAxis->grid()->setSubGridPen(gridPen);

    // Pour le 1er graphe :
    // Ajout de données :
    QVector<double> QualiteData;
    // TODO : TresoData doivent se MaJ à chaque tour
    QualiteData << 100 << 120 << 170 << 80 << 145 << 95 << 138;

    QVector<double> ErrResteDuStock;
    ErrResteDuStock << 15 << 20 << 10 << 30 << 15 << 25 << 15;

    // Traçage :
    customPlot->graph(0)->setData(ticks, QualiteData);
    customPlot->graph(1)->setDataValueError(ticks, QualiteData, ErrResteDuStock);
    customPlot->graph(1)->rescaleAxes(true);

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
