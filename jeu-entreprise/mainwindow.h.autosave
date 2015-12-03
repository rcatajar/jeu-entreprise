/* Fenêtre introductive du jeu, où l'utilisateur rentre son nom et le nombre d'IAs contre lesquelles il veut jouer.
 * Appellée par : null
 * Appelle : TurnWindow */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QDialogButtonBox>
#include <QPushButton>

#include "inputwidget.h"
#include "turnwindow.h"
#include "inputwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);


    ~MainWindow();

public slots:
    void openTurnWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *startButton;
    TurnWindow *mTurnWindow;

    InputWidget *temp;

};

#endif // MAINWINDOW_H
