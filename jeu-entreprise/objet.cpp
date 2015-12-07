#include <iostream>
#include <random>

#include "objet.h"
#include "entite.h"


using namespace std;

Objet::Objet(Entite* e):
    proprietaire(e){

    // qualité déterminée par une loi uniforme centrée sur 50;
    default_random_engine generator;
    normal_distribution<float> distribution(50, 15);
    qualite = distribution(generator);
    // On s'assure d'être en 1 et 99
    if (qualite <1){
        qualite = 1;
    }
    else if (qualite > 99){
        qualite = 99;
    }
}

Objet::Objet(Entite* e, int q):
    proprietaire(e){
    // qualité déterminée par une loi normale centré sur l'argument)
    default_random_engine generator;
    normal_distribution<float> distribution(q, 15);
    qualite = distribution(generator);
    // On s'assure d'être en 1 et 99
    if (qualite <1){
        qualite = 1;
    }
    else if (qualite > 99){
        qualite = 99;
    }
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
        proprietaire->retirer_au_stock(this);
        delete this;
    }

}
