#ifndef CLIENT_H
#define CLIENT_H

#include <vector>

#include "entite.h"
#include "objet.h"

class Client : public Entite
{
protected:
    // l'objet du client (s'il en a un)
    // j'utilise un pointeur car l'objet peut être null
    Objet* objet;

public:
    Client(const std:: string&, float);
    void set_objet(Objet*);
    Objet* get_objet() const;
    void achat(std::vector <Objet*>);
};

#endif // CLIENT_H
