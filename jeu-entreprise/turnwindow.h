#ifndef TURNWINDOW_H
#define TURNWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include "loadingwindow.h"

namespace Ui {
class TurnWindow;
}

class TurnWindow : public QWidget
{
    Q_OBJECT

public slots:
    void openLoadingWindow();

public:
    explicit TurnWindow(QWidget *parent = 0);
    ~TurnWindow();

private:
    Ui::TurnWindow *ui;
    LoadingWindow *mLoadingWindow;
};

#endif // TURNWINDOW_H
