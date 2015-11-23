#include <string>
#include <vector>

#include "entite.h"
#include "entreprise.h"
#include "objet.h"

using namespace std;

Entreprise::Entreprise(const std::string &n, float treso):
    Entite(n, treso){}

float Entreprise::get_prix_de_vente() const{
    return prix_de_vente;
}

void Entreprise::set_prix_de_vente(float x){
    prix_de_vente = x;
}

vector<Objet> Entreprise::produire(int n){
    /* Ici on devrait:
     * instancier n objets
     * les stocker dans le stock
     * faire baisser la treso de a + b * n
     * retourner un vecteur de ces objets
     */
    vector<Objet> objets;
    return objets;
}

void Entreprise::remove_objet(Objet * o){
    // TODO
    // Retire du vecteur d'objets le pointeur o
}
