#include <vector>
#include <string>
#include <iostream>
#include <typeinfo>
#include <math.h>

#include "entite.h"
#include "client.h"
#include "objet.h"
#include "entreprise.h"

using namespace std;

Client::Client(const std::string &n, float treso):
    Entite(n, treso){}

int Client::quantite_a_acheter(){
    // Retourne le nombre d'objet que le client veux acheter
    // Pour le moment, le client achete un objet uniquement s'il n'en a aucun
    if (stock.size() == 0){
        return 0;
    }
    return 1;
}
void Client::achat(std::vector <Objet*> objets_a_vendre){

    int n = objets_a_vendre.size();

    float tableau_preferences[n];
    float argent_restant[n];
    Entreprise *e[n];

    float norm = 0;
    int index_max = 0;

    for(int i=0; i<n; i++){
        e[i] = (Entreprise *) objets_a_vendre[i]->get_proprietaire();
        argent_restant[i] = tresorerie - e[i]->get_prix_de_vente();

        if(argent_restant[i] > 0){
            tableau_preferences[i] = argent_restant[i] * objets_a_vendre[i]->get_qualite();
            norm += tableau_preferences[i] * tableau_preferences[i];
        }
        else{
            tableau_preferences[i] = 0;
        }

    }
    if(norm != 0){ // si il y a bien un objet qu'peut acheter la dedans

        for(int i=0; i<n; i++){ // je boucle sur tous les objets que je peux acheter

            tableau_preferences[i] = tableau_preferences[i] / norm; // = 0 si on n'aimait pas l'objet, >0 sinon

            if(tableau_preferences[i] > tableau_preferences[index_max]){ // Je vais chercher l'objet que je préfère
                index_max = i;
            }
        }

        // je perds l'argent nécéssaire
        //cout << "avant l'achat : " << this->get_tresorerie() << endl;
        this->set_tresorerie(argent_restant[index_max]);
        //cout << "après l'achat : " << this->get_tresorerie() << endl;

        // l'entreprise effectue la vente (retire l'objet de son stock et augemente sa tréso)
        //cout << "avant l'achat : " << e[index_max]->get_tresorerie() << endl;
        e[index_max]->vente_objet(objets_a_vendre[index_max]);
        //cout << "après l'achat : " << e[index_max]->get_tresorerie() << endl;

        // je deviens propriétaire de l'objet et l'ajoute à mon stock
        //cout << "avant l'achat : " << objets_a_vendre[index_max]->get_proprietaire()->get_nom() << endl;
        this->ajouter_au_stock(objets_a_vendre[index_max]);
        //cout << "après l'achat : " << objets_a_vendre[index_max]->get_proprietaire()->get_nom() << endl;


    }

}
