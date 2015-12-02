#ifndef TURNWINDOW_H
#define TURNWINDOW_H

#include <QWidget>

namespace Ui {
class TurnWindow;
}

class TurnWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TurnWindow(QWidget *parent = 0);
    ~TurnWindow();

private:
    Ui::TurnWindow *ui;
};

#endif // TURNWINDOW_H
