#include <vector>
#include <algorithm>  // needed for retirer_au_stock
#include "QString"

#include "entite.h"
#include "objet.h"


using namespace std;

Entite::Entite(const QString &n, float x):
    nom(n),
    tresorerie(x){}

const QString & Entite::get_nom() const{
    return nom;
}

float Entite::get_tresorerie() const{
    return tresorerie;
}

void Entite::set_tresorerie(float x){
    tresorerie = x;
}

vector<Objet*> Entite::get_stock() const{
    return stock;
}

void Entite::ajouter_au_stock(Objet* objet){
    // on s'assure qu'on est le propriétaire de l'objet avant de l'ajouter a son stock
    objet->set_proprietaire(this);
    stock.push_back(objet);
}

void Entite::retirer_au_stock(Objet* objet){
    // erase-remove idiom, see http://stackoverflow.com/q/3385229
    stock.erase(std::remove(stock.begin(), stock.end(), objet), stock.end());
}

void Entite::gestion_des_stocks(){
    // On copie le stock courant, car certains objets vont etre retirer
    // du stock pendant l'iteration, ce qui empeche d'iterer sur stock directement
    vector <Objet*> copie_stock = stock;
    for(int i=0; i < copie_stock.size(); i++){
        copie_stock[i]->check_qualite();
    }
}
