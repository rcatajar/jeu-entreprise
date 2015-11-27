#include <string>
#include <vector>
#include <algorithm>  // needed for retirer_au_stock

#include "entite.h"
#include "entreprise.h"
#include "objet.h"
#include "iostream"

using namespace std;

Entreprise::Entreprise(const std::string &n, float treso, bool _ia):
    Entite(n, treso){
    cout_fixe = 200;
    cout_variable = 10;
    ia = _ia;

    /*std::cout << "creation d'entreprise avec pour "*/
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

bool Entreprise::is_ia(){
    return ia;
}

void Entreprise::produire(int n){
    // Produit n objets et les ajoute au stock de l'entreprise
    // Diminue sa trésorerie du cout de production associé
    float cout_prod = cout_fixe + n * cout_variable;
    for (int i=0; i<n; i++){
        Objet* objet_cree = new Objet(this);
        ajouter_au_stock(objet_cree);
    }
    tresorerie -= cout_prod;
}

void Entreprise::vente_objet(Objet * objet){
    retirer_au_stock(objet);
    tresorerie = tresorerie + prix_de_vente;
}

void Entreprise::phase_de_marketing(){
    if(ia == true){
        prix_de_vente = 1.5 * (cout_fixe / stock.size() + cout_variable);
    } else{
        bool intervention_user = false;
        float valeur_entree = 0;
        while(!intervention_user){
            cout << "Entrez votre prix de vente : " << endl;
            if (cin >> valeur_entree){
                intervention_user = true;
            }
            else{
                cout << "Nombre invalide, mauvais caractère" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        prix_de_vente = valeur_entree;
    }
}

void Entreprise::phase_de_production(){
    if(ia == true){
        int production = (tresorerie - cout_fixe) / (2 * cout_variable);
        produire(production);
    } else {
        bool intervention_user = false;
        int valeur_entree = 0;

        while(!intervention_user){ // boucle pour être sur qu'on produit bien un nombre entier de vélo
            cout << "Combien de vélos voulez vous produire ?" << endl;
            cout << "Vous avez déjà : " << stock.size() << " vélos." << endl;
            cout << "Votre trésorerie est de : " << tresorerie << endl;
            cout << "Votre cout fixe est de : " << cout_fixe;
            cout << " et votre cout variable de : " << cout_variable << endl;
            cout << endl;

            if (cin >> valeur_entree && tresorerie > cout_fixe + valeur_entree * cout_variable){
                intervention_user = true;
            }
            else{
                cout << "Nombre invalide, mauvais caractère ou vous n'avez pas assez d'argent" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        produire(valeur_entree);
        cout << "Vous produisez :  " << valeur_entree << " vélo(s)." << endl;
        cout << "Nouvelle trésorerie : " << tresorerie << endl;
        cout << "Nouveau stock :" << stock.size() << endl;
        cout << endl;
    }
}
