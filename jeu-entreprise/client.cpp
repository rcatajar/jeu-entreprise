#include <vector>
#include <iostream>
#include <typeinfo>
#include <math.h>
#include <QString>

#include "entite.h"
#include "client.h"
#include "objet.h"
#include "entreprise.h"


using namespace std;

Client::Client(const QString &n, float treso):
    Entite(n, treso){
    revenu = (rand() % 99) + 1; // On affecte a chaque client un revenu aléatoire entre 1 et 99.
    preference_qualite = (rand() % 99) / 100 + 1;
    preference_tresorerie = (rand() % 99) / 100 + 1;
}

int Client::quantite_a_acheter(){
    // Retourne le nombre d'objet que le client veux acheter
    // Pour le moment, le client achete un objet uniquement s'il n'en a aucun
    if (stock.size() > 0){
        return 0;
    }
    return 1;
}

int Client::get_revenu() const{
    return revenu;
}

void Client::achat(std::vector <Objet*> objets_a_vendre){

    int n = objets_a_vendre.size();

    vector <float> tableau_preferences;
    vector <float> argent_restant;
    vector <Entreprise*> e;

    float norm = 0;
    int index_max = 0;

    for(int i=0; i<n; i++){
        e.push_back((Entreprise*) objets_a_vendre[i]->get_proprietaire());
        argent_restant.push_back(tresorerie - e[i]->get_prix_de_vente());
        float pref;
        if(argent_restant[i] > 0){
            pref = pow(argent_restant[i], preference_tresorerie) * pow(objets_a_vendre[i]->get_qualite(), preference_qualite);
            norm += pref * pref;
        } else{
            pref = 0;
        }
        tableau_preferences.push_back(pref);

    }
    if(norm != 0){ // si il y a bien un objet qu'peut acheter la dedans

        for(int i=0; i<n; i++){ // je boucle sur tous les objets que je peux acheter
            tableau_preferences[i] = tableau_preferences[i] / norm; // = 0 si on n'aimait pas l'objet, >0 sinon
            if(tableau_preferences[i] > tableau_preferences[index_max]){ // Je vais chercher l'objet que je préfère
                index_max = i;
            }
        }
        // On retire le prix de l'objet à la tresorerie du client
        this->set_tresorerie(argent_restant[index_max]);

        // l'entreprise effectue la vente (retire l'objet de son stock et augemente sa tréso)
        e[index_max]->vente_objet(objets_a_vendre[index_max]);

        // le client s'approprie l'objet
        this->ajouter_au_stock(objets_a_vendre[index_max]);
    }
}

void Client::phase_de_revenu(){
    tresorerie = tresorerie + revenu;

}
