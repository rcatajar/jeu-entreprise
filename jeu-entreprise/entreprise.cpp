#include "entite.h"
#include "entreprise.h"

using namespace std;

Entreprise::Entreprise(const std::string &n, float treso):
    Entite(n, treso){}

float Entreprise::get_prix_de_vente() const{
    return prix_de_vente;
}

void Entreprise::set_prix_de_vente(float x){
    prix_de_vente = x;
}
