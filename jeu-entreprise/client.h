#ifndef CLIENT_H
#define CLIENT_H

#include <vector>
#include <QString>

#include "entite.h"


class Client : public Entite
{
private:
    int revenu;
    float preference_qualite;
    float preference_tresorerie;

public:
    Client(const QString&, float);

    int quantite_a_acheter();
    int get_revenu() const;
    void achat(std::vector <Objet*>);
    void phase_de_revenu();
};

#endif // CLIENT_H
