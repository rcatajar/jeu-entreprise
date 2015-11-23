#include <iostream>


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

void Objet::check_qualite(){
    // On détruit l'objet aléatoirement en fonction de sa qualite
    int roll = rand() % 100 + 1;  // nombre aléatoire entre 1 et 100.
    // On compare le roll à la qualité
    if (roll >= qualite){
        // On retire l'objet de son propriétaire et on le détruit
        proprietaire->remove_objet(this);
        delete this;
    }

}
