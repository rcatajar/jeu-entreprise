#include "graphsfinance.h"
#include "ui_graphsfinance.h"

GraphsFinance::GraphsFinance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphsFinance)
{
    ui->setupUi(this);

    GraphsFinance::ajouterGraphTresoCA(ui->graph1);
    GraphsFinance::ajouterGraphRepartitionCouts(ui->graph2);

}

GraphsFinance::~GraphsFinance()
{
    delete ui;
}

void GraphsFinance::ajouterGraphTresoCA(QCustomPlot *customPlot)
{

    // create empty bar chart objects:
    QCPBars *CA = new QCPBars(customPlot->xAxis, customPlot->yAxis);

    customPlot->addPlottable(CA);

    customPlot->addGraph(customPlot->xAxis, customPlot->yAxis2);


    // set names and colors:
    QPen pen;
    pen.setWidthF(1.2);

    pen.setColor(QColor(255, 131, 0));
    pen.setColor(QColor(1, 92, 191));
    CA->setName("CA");
    pen.setColor(QColor(150, 222, 0));
    CA->setPen(pen);
    CA->setBrush(QColor(150, 222, 0, 70));

    // prepare x axis with "Turn" labels:
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

    // prepare y axis:
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

    // Add data:
    QVector<double> CAData;
    // TODO : CAData doivent se MaJ à chaque tour
    CAData  << 0.86*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;
    CA->setData(ticks, CAData);

    QVector<double> TresoData;
    // TODO : TresoData doivent se MaJ à chaque tour
    TresoData << 1 << 2 << 5 << 3 << 7 << 2 << 6;

    customPlot->graph(0)->setData(ticks, TresoData);
    customPlot->yAxis2->setVisible(true);
    // TODO : range doit évoluer automatiquement avec les données
    customPlot->yAxis2->setRangeUpper(8);
    customPlot->yAxis2->setLabel("Trésorerie");


    // setup legend:
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
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    customPlot->xAxis->setRange(-1, 1);
    customPlot->yAxis->setRange(0, 1);
    customPlot->replot();
}
