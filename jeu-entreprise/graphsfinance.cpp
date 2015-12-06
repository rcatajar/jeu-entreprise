#include "graphsfinance.h"
#include "ui_graphsfinance.h"
#include "moteurjeu.h"


GraphsFinance::GraphsFinance(QWidget *parent, MoteurJeu* _moteur) :
    QWidget(parent),
    ui(new Ui::GraphsFinance)
{
    moteur = _moteur;
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
    pen0.setColor(QColor(1, 91, 191));
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
    customPlot->xAxis->setRange(-0.5, moteur->historique->tour + 0.5);

    // Préparation de l'axe Y:
    QVector<double> ca = moteur->historique->get_ca();
    double max_ca = *std::max_element(ca.begin(), ca.end());

    customPlot->yAxis->setRange(0, max_ca + 10);
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
    CA->setData(ticks, ca);

    // Pour le 2e graphe (plus classique) :
    // Ajout de données :
    QVector<double> treso = moteur->historique->get_tresorerie();
    double max_treso = *std::max_element(treso.begin(), treso.end());

    // Traçage :
    customPlot->graph(0)->setData(ticks, treso);
    customPlot->yAxis2->setVisible(true);
    // TODO : range doit évoluer automatiquement avec les données
    customPlot->yAxis2->setRange(0, max_treso + 10);
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

    // Préparation de l'axe Y :
    customPlot->yAxis->setRange(0, moteur->historique->max_cout() + 10);
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
    investissements->setData(ticks, moteur->historique->get_investissement());
    coutsVariables->setData(ticks, moteur->historique->get_cout_variable());
    coutsFixes->setData(ticks, moteur->historique->get_cout_fixe());

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
