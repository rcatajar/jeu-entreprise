#include <string>

#include "entite.h"

using namespace std;

Entite::Entite(const string &n, float x):
    nom(n),
    tresorerie(x){}

const string & Entite::get_nom() const{
    return nom;
}

float Entite::get_tresorerie() const{
    return tresorerie;
}

void Entite::set_tresorerie(float x){
    tresorerie = x;
}
