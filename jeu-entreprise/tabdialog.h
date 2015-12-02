#ifndef TABDIALOG_H
#define TABDIALOG_H

#include <QWidget>
#include <QTabWidget>
#include <QDialogButtonBox>
#include <QDialog>

namespace Ui {
class TabDialog;
}

class TabDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TabDialog(QWidget *parent = 0);
    ~TabDialog();

private:
    Ui::TabDialog *ui;

    QTabWidget *tabWidget;
    QDialogButtonBox *buttonBox;
};

#endif // TABDIALOG_H
