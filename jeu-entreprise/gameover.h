#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>

#include "moteurjeu.h"

namespace Ui {
class GameOver;
}

class GameOver : public QWidget
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent = 0, MoteurJeu* m = NULL);
    ~GameOver();

private:
    Ui::GameOver *ui;
    MoteurJeu* moteur;
};

#endif // GAMEOVER_H
