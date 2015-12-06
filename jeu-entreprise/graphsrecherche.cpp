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

    // Réglage de l'épaisseur des barres
    investissementCumule->setWidth(0.4);
    investissementRecherche->setWidth(0.4);

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
    customPlot->yAxis->setRange(0, moteur->historique->get_investissement_max() + 500.) ;
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

    // Noms et couleurs graph 0:
    QPen pen0;
    pen0.setWidthF(1.2);

    pen0.setColor(QColor(1, 92, 191));
    customPlot->graph(0)->setPen(pen0);
    customPlot->graph(0)->setBrush(QColor(1, 92, 191, 50));

    // Préparation de l'axe X :
    QVector<double> ticks = moteur->historique->get_ticks();
    QVector<QString> labels = moteur->historique->get_labels();

    customPlot->xAxis->setAutoTicks(false);
    customPlot->xAxis->setAutoTickLabels(false);
    customPlot->xAxis->setTickVector(ticks);
    customPlot->xAxis->setTickVectorLabels(labels);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTickCount(0);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->setRange(0.5, moteur->historique->tour + 0.5);

    // Préparation de l'axe Y:
    customPlot->yAxis->setRange(0, 200); // ici
    customPlot->yAxis->setPadding(5);
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


    // Traçage :
    customPlot->graph(0)->setData(ticks, moteur->historique->get_qualite_moyenne());


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
