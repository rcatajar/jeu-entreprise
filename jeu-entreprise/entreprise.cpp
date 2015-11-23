#include <string>
#include <vector>

#include "entite.h"
#include "entreprise.h"
#include "objet.h"
#include "iostream"

using namespace std;

Entreprise::Entreprise(const std::string &n, float treso):
    Entite(n, treso){
    cout_fixe = 200;
    cout_variable = 10;

    /*std::cout << "creation d'entreprise avec pour "*/
}

Entreprise::Entreprise(const std::string &n, float treso, float param_cout_fixe, float param_cout_variable):
    Entite(n, treso){
    cout_fixe = param_cout_fixe;
    cout_variable = param_cout_variable;

}

float Entreprise::get_prix_de_vente() const{
    return prix_de_vente;
}

void Entreprise::set_prix_de_vente(float x){
    prix_de_vente = x;
}

float Entreprise::get_cout_fixe() const{
    return cout_fixe;
}

void Entreprise::set_cout_fixe(float x){
    cout_fixe = x;
}

float Entreprise::get_cout_variable() const{
    return cout_variable;
}

void Entreprise::set_cout_variable(float x){
    cout_variable = x;
}


vector <Objet*> Entreprise::get_stock() const{
    return stock;
}

void Entreprise::ajouter_au_stock(Objet* objet){
    stock.push_back(objet);
}

void Entreprise::retirer_au_stock(Objet* objet){
    int index = 0;
    bool appartenance = false;

    for(int i=0; i<stock.size(); i++){
        if(stock[i] == objet){
            index = i;
            appartenance = true;
        }
    }
    if(appartenance){
        stock.erase(stock.begin()+index);
    }
}

vector<Objet> Entreprise::produire(int n){
    /* Ici on devrait:
     * instancier n objets
     * lstocker leur pointeurs dans le stock
     * faire baisser la treso de a + b * n
     * retourner un vecteur de ces objets
     */

    vector <Objet> objets;

    for (int i=0; i<n; i++){

        Objet objet_cree = Objet(this);

        objets.insert(objets.end(), objet_cree);
        ajouter_au_stock(&objet_cree);
    }

    tresorerie -= cout_fixe + n*cout_variable;

    return objets;
}
