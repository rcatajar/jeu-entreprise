#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QDialogButtonBox>
#include <QPushButton>

#include "tabdialog.h"

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
    TabDialog *mTabDialog;
    QPushButton *startButton;

    //    QTabWidget *tabWidget;
    //    QDialogButtonBox *buttonBox;
};

#endif // MAINWINDOW_H
