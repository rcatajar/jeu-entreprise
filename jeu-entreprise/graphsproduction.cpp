#include "graphsproduction.h"
#include "ui_graphsproduction.h"

#include "moteurjeu.h"

GraphsProduction::GraphsProduction(QWidget *parent, MoteurJeu* _moteur) :
    QWidget(parent),
    ui(new Ui::GraphsProduction)
{
    moteur = _moteur;
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
    // C'est trop relou de faire toutes les entreprises
    //pour le moment je plot que le joueur

    // Création de 3 barcharts vides :
    // TODO : relier au nombre d'entreprises
    QCPBars *plot = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    customPlot->addPlottable(plot);
    // Noms et couleurs :
    QPen pen;
    pen.setWidthF(1.2);
    plot->setName(moteur->historique->nom_joueur);
    pen.setColor(QColor(150, 222, 0));
    plot->setPen(pen);
    plot->setBrush(QColor(150, 222, 0, 70));

    // Préparation de l'axe X :
    QVector<double> ticks = moteur->historique->get_ticks();
    QVector<QString> labels = moteur->historique->get_labels();
    QVector<double> prod = moteur->historique->get_production();
    double max = *std::max_element(prod.begin(), prod.end());
    customPlot->xAxis->setAutoTicks(false);
    customPlot->xAxis->setAutoTickLabels(false);
    customPlot->xAxis->setTickVector(ticks);
    customPlot->xAxis->setTickVectorLabels(labels);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTickCount(0);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->setRange(0.5, moteur->historique->tour + 0.5);
    plot->setData(ticks, prod);

    // Préparation de l'axe Y :
    customPlot->yAxis->setRange(0, max + 10);
    customPlot->yAxis->setPadding(5);
    customPlot->yAxis->setLabel("Nb vélos produits");
    customPlot->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    customPlot->yAxis->grid()->setSubGridPen(gridPen);

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
    customPlot->graph(1)->setName("Nb vélos invendus");

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
    QVector<double> ticks = moteur->historique->get_ticks();
    QVector<QString> labels =  moteur->historique->get_labels();

    customPlot->xAxis->setAutoTicks(false);
    customPlot->xAxis->setAutoTickLabels(false);
    customPlot->xAxis->setTickVector(ticks);
    customPlot->xAxis->setTickVectorLabels(labels);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTickCount(0);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->grid()->setVisible(true);
    // TODO : range doit évoluer avec nombre de tours passés
    customPlot->xAxis->setRange(-0.5, moteur->historique->tour + 0.5);

    // Préparation de l'axe Y:
    // TODO : range doit évoluer automatiquement avec les données
    customPlot->yAxis->setRange(0, moteur->historique->max_vente_invendu() + 10);
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
    QVector<double> VendusData = moteur->historique->get_vente();
    // Pour le 2e graphe :
    QVector<double> RestantsData = moteur->historique->get_invendu();

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
