/* Fenêtre générée à chaque tour.
 * Présente les informations des tours précédents (TabWidget + Graphs).
 * Permet les inputs pour passer au tour suivant (InputWidget).
 * Appelée par : MainWindow, LoadingWindow
 * Intègre : TabWidget, InputWidget
 * Appelle : LoadingWindow */

#ifndef TURNWINDOW_H
#define TURNWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include "loadingwindow.h"
#include "moteurjeu.h"

namespace Ui {
class TurnWindow;
}

class TurnWindow : public QWidget
{
    Q_OBJECT

public slots:
    void openLoadingWindow();

public:
    explicit TurnWindow(QWidget *parent = 0, MoteurJeu* moteur = NULL);
    MoteurJeu* moteur;
    ~TurnWindow();

private:
    Ui::TurnWindow *ui;
    LoadingWindow *mLoadingWindow;
};

#endif // TURNWINDOW_H
