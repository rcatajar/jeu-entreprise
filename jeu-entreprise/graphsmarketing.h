#ifndef GRAPHSMARKETING_H
#define GRAPHSMARKETING_H

#include <QWidget>

namespace Ui {
class GraphsMarketing;
}

class GraphsMarketing : public QWidget
{
    Q_OBJECT

public:
    explicit GraphsMarketing(QWidget *parent = 0);
    ~GraphsMarketing();

private:
    Ui::GraphsMarketing *ui;
};

#endif // GRAPHSMARKETING_H
