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

void Client::achat(std::vector<Objet *>){
    // on a en entrée une liste de pointeurs sur tous les objets du marché
    // le client associe à chaque pointeur une préférence
    // on renvoie la préférence la plus élevée (dans un premier temps, le client achete l'objet qu'il préfère seulement
    // le client possède cet objet avec un getobjet
    // l'entreprise gagne de l'argent avec set_tresorerie
    // l'objet est retiré du stock de l'entreprise

}


