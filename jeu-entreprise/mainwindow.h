#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QDialogButtonBox>
#include <QPushButton>

#include "tabwidget.h"
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
    void openNewWindow();

private:
    Ui::MainWindow *ui;
    TabWidget *mTabWidget;
    QPushButton *startButton;
    InputWidget *mInputWidget;
    TurnWindow *mTurnWindow;

    //    QTabWidget *tabWidget;
    //    QDialogButtonBox *buttonBox;
};

#endif // MAINWINDOW_H
