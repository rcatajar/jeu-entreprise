#ifndef GRAPHSRECHERCHE_H
#define GRAPHSRECHERCHE_H

#include <QWidget>

namespace Ui {
class GraphsRecherche;
}

class GraphsRecherche : public QWidget
{
    Q_OBJECT

public:
    explicit GraphsRecherche(QWidget *parent = 0);
    ~GraphsRecherche();

private:
    Ui::GraphsRecherche *ui;
};

#endif // GRAPHSRECHERCHE_H
