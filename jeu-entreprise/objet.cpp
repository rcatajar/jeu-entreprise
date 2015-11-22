#include "objet.h"
#include "entite.h"

Objet::Objet(Entite* e):
    proprietaire(e){
    qualite = rand() % 99 + 1; // qualité aléatoire entre 1 et 99
}

void Objet::set_qualite(int q){
    qualite = q;
}

void Objet::set_proprietaire(Entite* e){
    proprietaire = e;
}

Entite* Objet::get_proprietaire() const{
    return proprietaire;
}

int Objet::get_qualite() const{
    return qualite;
}
