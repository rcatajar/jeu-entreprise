/* Widget rassemblant tous les inputs du jouer lors d'un tour
 * Appelée par : TurnWindow */

#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QWidget>
#include <QTabWidget>

#include "tabwidget.h"
#include "moteurjeu.h"

namespace Ui {
class InputWidget;
}

class InputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InputWidget(QWidget *parent = 0, MoteurJeu* moteur = NULL);
    ~InputWidget();
    MoteurJeu* moteur;
    void initialiser();
    int get_prix() const;
    int get_production() const;
    int get_recherche() const;

public slots:
    void changement_production(int);
    void changement_recherche(int);

private:
    Ui::InputWidget *ui;
    QTabWidget *tabWidget;
    TabWidget *mTabWidget;
};

#endif // INPUTWIDGET_H
