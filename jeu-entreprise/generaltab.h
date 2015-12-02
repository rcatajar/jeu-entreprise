#ifndef GENERALTAB_H
#define GENERALTAB_H

#include <QWidget>
#include <QFileInfo>

namespace Ui {
class GeneralTab;
}

class GeneralTab : public QWidget
{
    Q_OBJECT

public:
    explicit GeneralTab(const QFileInfo &fileInfo, QWidget *parent = 0);
    ~GeneralTab();

private:
    Ui::GeneralTab *ui;
};

#endif // GENERALTAB_H
