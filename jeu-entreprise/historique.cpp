#include "historique.h"
#include <QString>
using namespace std;
Historique::Historique(int _tour, int _tour_max, QString _nom_joueur, int _nombre_ias, int _nombre_clients)
{
    tour = _tour;
    tour_max = _tour_max;
    nom_joueur = _nom_joueur;
    nombre_ias = _nombre_ias;
    nombre_clients = _nombre_clients;

}
