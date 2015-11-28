#include <string>
#include <vector>
#include <algorithm>  // needed for retirer_au_stock

#include "entite.h"
#include "entreprise.h"
#include "objet.h"
#include "iostream"

using namespace std;

Entreprise::Entreprise(const std::string &n, float treso):
    Entite(n, treso){
    cout_fixe = 200;
    cout_variable = 10;
    investissement_realise = 0;
    qualite_marginale = 5; // ce facteur correspond à l'augmentation de la qualité pour un investissement de 1000
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

float Entreprise::get_investissement_realise() const{
    return investissement_realise;
}

void Entreprise::produire(int n){
    // Produit n objets et les ajoute au stock de l'entreprise
    // Diminue sa trésorerie du cout de production associé
    float cout_prod = cout_fixe + n * cout_variable;
    for (int i=0; i<n; i++){
        Objet* objet_cree = new Objet(this, 50 + qualite_marginale * investissement_realise / 1000);
        ajouter_au_stock(objet_cree);
    }
    tresorerie -= cout_prod;
}

void Entreprise::investir(int n){

    // un investissement de 1000 augmentera la recherche du montant de qualite marginale, initialisé à 5

    int recherche_realise = (int)  qualite_marginale * investissement_realise / 1000;

    if(recherche_realise + qualite_marginale * n / 1000 < 100){
        investissement_realise =+ n;
        tresorerie -= n;
    }
    else{
        cout << "Vous avez déjà investi la somme maximale en recherche" << endl;
    }
}

void Entreprise::vente_objet(Objet * objet){
    retirer_au_stock(objet);
    tresorerie = tresorerie + prix_de_vente;
}
