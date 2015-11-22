#include "objet.h"
#include "entite.h"

Objet::Objet(Entite e):
    proprietaire(e){
    qualite = rand() % 99 + 1; // qualité aléatoire entre 1 et 99
}
