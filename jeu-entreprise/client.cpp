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
    Entite(n, treso){
    // au début, le client n'as pas d'objet
    // on assigne donc le pointeur NULL
    //(grosso modo c'est comme None en python)
    objet = NULL;
}

void Client::set_objet(Objet* o){
    objet = o;
    // Quand le client s'attribue un objet, on change le proprio dans l'objet
    objet->set_proprietaire(this);
}

Objet* Client::get_objet() const{
    return objet;
}

void Client::remove_objet(Objet*){
    // On n'appelle pas set_objet, car set_objet va essayé de faire
    // objet->set_proprietaire(this), ce qui fait une segfault car objet = NULL
    objet = NULL;
}

void Client::gestion_des_stocks(){
    if(objet != NULL){
        objet->check_qualite();
    }
}

void Client::achat(std::vector <Objet*> objets_a_vendre){

    int n = objets_a_vendre.size();

    float tableau_preferences[n];
    float argent_restant[n];
    Entreprise *e[n];

    float norm = 0;
    int index_max = 0;


    if (n==0){
        // do nothing
    }
    else{
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

            // l'entreprise reçoit l'argent que j'ai dépensé
            //cout << "avant l'achat : " << e[index_max]->get_tresorerie() << endl;
            e[index_max]->set_tresorerie(e[index_max]->get_tresorerie() + e[index_max]->get_prix_de_vente());
            //cout << "après l'achat : " << e[index_max]->get_tresorerie() << endl;

            // je deviens propriétaire de l'objet
            //cout << "avant l'achat : " << objets_a_vendre[index_max]->get_proprietaire()->get_nom() << endl;
            objets_a_vendre[index_max]->set_proprietaire(this);
            //cout << "après l'achat : " << objets_a_vendre[index_max]->get_proprietaire()->get_nom() << endl;

            // l'entreprise perd l'objet de son stock
            e[index_max]->retirer_au_stock(objets_a_vendre[index_max]);

        }
        else{ // sinon il n'y a aucun objet qu'on peut acheter
            // do nothing
        }




    }

}
