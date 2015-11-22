#ifndef OBJET_H
#define OBJET_H

#include "entite.h"

class Objet
{
protected:
    int qualite;  // facteur de qualité de l'objet, % entre 1 et 99
    Entite proprietaire; // proprio de l'objet
public:
    Objet(Entite);
    void set_qualite(int);
    void set_proprietaire(Entite);
    Entite get_proprietaire() const;
    int get_qualite() const;
};

#endif // OBJET_H
