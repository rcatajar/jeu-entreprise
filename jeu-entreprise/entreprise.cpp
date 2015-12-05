#include <vector>
#include <algorithm>  // needed for retirer_au_stock

#include "entite.h"
#include "entreprise.h"
#include "objet.h"
#include "iostream"

#include <QString>

using namespace std;

Entreprise::Entreprise(const QString &n, float treso, bool _ia):
    Entite(n, treso){
    cout_fixe = 200;
    cout_variable = 10;
    investissement_realise = 0;
    qualite_marginale = 0;
    max_recherche = false;
    ia = _ia;

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

int Entreprise::get_qualite_marginale() const{
    return qualite_marginale;
}

bool Entreprise::is_ia() const{
    return ia;
}

bool Entreprise::recherche_max_atteinte() const{
    return max_recherche;
}

void Entreprise::produire(int n){
    // Produit n objets et les ajoute au stock de l'entreprise
    // Diminue sa trésorerie du cout de production associé
    float cout_prod = cout_fixe + n * cout_variable;
    for (int i=0; i<n; i++){
        Objet* objet_cree = new Objet(this, 50 + qualite_marginale);
        ajouter_au_stock(objet_cree);
    }
    tresorerie -= cout_prod;
}

void Entreprise::investir(int n){
    // Investir de l'argent permet d'améliorer la qualité des objets produits
    // La qualité marginale augmente de 5 tout les seuil=1000$ investi
    int seuil = 1000;

    investissement_realise += n;
    tresorerie -= n;
    if (investissement_realise > 10 * seuil){
        qualite_marginale = 50;
        max_recherche = true;
    }
    else{
        qualite_marginale = 5 * (investissement_realise / seuil);
    }
}

void Entreprise::vente_objet(Objet * objet){
    retirer_au_stock(objet);
    tresorerie = tresorerie + prix_de_vente;
}

void Entreprise::phase_de_marketing(int input){
    if(ia == true){
        prix_de_vente = 1.5 * (cout_fixe / (stock.size() + 10) + cout_variable);
    } else{
        if (input >= 0){
            prix_de_vente = input;
        }
        else{
            prix_de_vente = 0;
        }
    }
}

void Entreprise::phase_de_production(int input){
    if(ia){
        int production = (tresorerie - cout_fixe) / (2 * cout_variable);
        produire(production);
    } else {
        produire(input);

    }
}

void Entreprise::phase_de_recherche(int input){
    // L'IA investi entre 0 et 1000$ par tour tant qu'elle n'a pas maxé sa recherche
    if(ia && !max_recherche){
        int investissement = rand() % 1000;
        investir(investissement);
    }

    else {

        if(input > 0){
            investir(input);
        }
    }
}
