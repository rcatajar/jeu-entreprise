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

void Entreprise::produire(int n){
    /* Ici on devrait:
     * instancier n objets
     * lstocker leur pointeurs dans le stock
     * faire baisser la treso de a + b * n
     * retourner un vecteur de ces objets
     */
    for (int i=0; i<n; i++){

        Objet* objet_cree = new Objet(this);
        ajouter_au_stock(objet_cree);
    }

    tresorerie -= cout_fixe + n*cout_variable;
}

void Entreprise::remove_objet(Objet * o){
    // TODO
    // Retire du vecteur d'objets le pointeur o
}

void Entreprise::gestion_des_stocks(){
    // TODO
    // Parcourir le vecteur d'objet et appeler check_qualite
}
