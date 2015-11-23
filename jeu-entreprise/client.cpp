#include "entite.h"
#include "client.h"
#include "objet.h"

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
