#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QDialogButtonBox>
#include <QPushButton>

#include "inputwidget.h"
#include "turnwindow.h"

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

};

#endif // MAINWINDOW_H
