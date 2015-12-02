#ifndef PERMISSIONSTAB_H
#define PERMISSIONSTAB_H

#include <QWidget>
#include <QFileInfo>

namespace Ui {
class PermissionsTab;
}

class PermissionsTab : public QWidget
{
    Q_OBJECT

public:
    explicit PermissionsTab(const QFileInfo &fileInfo, QWidget *parent = 0);
    ~PermissionsTab();

private:
    Ui::PermissionsTab *ui;
};

#endif // PERMISSIONSTAB_H
