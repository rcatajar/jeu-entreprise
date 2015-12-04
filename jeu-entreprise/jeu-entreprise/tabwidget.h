#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QWidget>
#include <QTabWidget>
#include <QDialogButtonBox>
#include <QDialog>

namespace Ui {
class TabWidget;
}

class TabWidget : public QDialog
{
    Q_OBJECT

public:
    explicit TabWidget(QWidget *parent = 0);
    ~TabWidget();

private:
    Ui::TabWidget *ui;

    QTabWidget *tabWidget;
    QDialogButtonBox *buttonBox;
};

#endif // TABWIDGET_H
