/* TabWidget,appelé à l'intérieur de TurnWindow, présente les différentes classes "Graphs" sous forme d'onglets.
 * Appelée par : TurnWindow
 * Intègre : GraphsFinance, GraphsProduction, GraphsRecherche, GraphsMarketing */

#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QWidget>
#include <QTabWidget>
#include <QDialogButtonBox>
#include <QDialog>

#include "moteurjeu.h"

namespace Ui {
class TabWidget;
}

class TabWidget : public QDialog
{
    Q_OBJECT

public:
    explicit TabWidget(QWidget *parent = 0, MoteurJeu* m = NULL);
    ~TabWidget();
    MoteurJeu* moteur;

private:
    Ui::TabWidget *ui;

    QTabWidget *tabWidget;
    QDialogButtonBox *buttonBox;
};

#endif // TABWIDGET_H
