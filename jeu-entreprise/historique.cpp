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

QVector <double> Historique::get_ticks(){
    QVector <double> ticks;
    for (int i=0; i <= tour; i++){
        ticks.push_back(i);
    }
    return ticks;
}

QVector <QString> Historique::get_labels(){
    QVector <QString> labels;
    for (int i=0; i <= tour; i++){
        QString label = QString("Tour %1").arg(i);
        labels.push_back(label);
    }
    return labels;
}

QVector <double> Historique::get_tresorerie(){
    QVector <double> treso;
    for (int i=0; i <= tour; i++){
        treso.push_back(tresoreries[i][0]);
    }
    return treso;
}

QVector <double> Historique::get_ca(){
    QVector <double> ca;
    for (int i = 0; i <= tour; i++){
        ca.push_back(ventes[i][0] * prix_de_vente[i][0]);
    }
    return ca;
}
