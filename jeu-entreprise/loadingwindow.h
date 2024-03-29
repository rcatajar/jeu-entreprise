/* Fenêtre affichée lors du chargement du tour suivant. Spécificité : processus circulaire
 * Appelée par : TurnWindow
 * Appelle : TurnWindow */

#ifndef LOADINGWINDOW_H
#define LOADINGWINDOW_H

#include <QWidget>
#include "moteurjeu.h"


namespace Ui {
class LoadingWindow;
}

class LoadingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoadingWindow(QWidget *parent = 0, MoteurJeu* m = NULL);
    ~LoadingWindow();
    MoteurJeu* moteur;

private:
    Ui::LoadingWindow *ui;
};

#endif // LOADINGWINDOW_H
