#ifndef GRAPHSPRODUCTION_H
#define GRAPHSPRODUCTION_H

#include <QWidget>

namespace Ui {
class GraphsProduction;
}

class GraphsProduction : public QWidget
{
    Q_OBJECT

public:
    explicit GraphsProduction(QWidget *parent = 0);
    ~GraphsProduction();

private:
    Ui::GraphsProduction *ui;
};

#endif // GRAPHSPRODUCTION_H
