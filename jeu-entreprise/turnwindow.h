#ifndef TURNWINDOW_H
#define TURNWINDOW_H

#include <QWidget>

namespace Ui {
class turnWindow;
}

class turnWindow : public QWidget
{
    Q_OBJECT

public:
    explicit turnWindow(QWidget *parent = 0);
    ~turnWindow();

private:
    Ui::turnWindow *ui;
};

#endif // TURNWINDOW_H
