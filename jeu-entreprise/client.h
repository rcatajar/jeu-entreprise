#ifndef CLIENT_H
#define CLIENT_H

#include <vector>

#include "entite.h"

class Client : public Entite
{
private:
    float preference_qualite;
    float preference_tresorerie;

public:
    Client(const std:: string&, float);
    int quantite_a_acheter();
    void achat(std::vector <Objet*>);
};

#endif // CLIENT_H
