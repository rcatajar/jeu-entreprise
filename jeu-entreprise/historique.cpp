#include "historique.h"
#include <QString>
using namespace std;
Historique::Historique(int _tour, int _tour_max, QString _nom_joueur, int _nombre_ias, int _nombre_clients, int _cout_fixe, int _cout_variable)
{
    tour = _tour;
    tour_max = _tour_max;
    nom_joueur = _nom_joueur;
    nombre_ias = _nombre_ias;
    nombre_clients = _nombre_clients;
    cout_fixe = _cout_fixe;
    cout_variable = _cout_variable;

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

QVector <double> Historique::get_cout_fixe(){
    QVector <double> fixe;
    fixe.push_back(0);
    for (int i = 1; i <= tour; i++){
        fixe.push_back(cout_fixe);
    }
    return fixe;
}


QVector <double> Historique::get_cout_variable(){
    QVector <double> variable;
    for (int i = 0; i <= tour; i++){
        variable.push_back(productions[i][0] * cout_variable);
    }
    return variable;
}

QVector <double> Historique::get_investissement(){
    QVector <double> invest;
    invest.push_back(0);
    for (int i = 1; i <= tour; i++){
        invest.push_back(investissements_recherche[i][0] - investissements_recherche[i - 1][0]);
    }
    return invest;
}

QVector <double> Historique::get_investissement_cumule(){
    QVector <double> invest;
    QVector <double> invest_cumule;
    double tampon = 0;

    invest = get_investissement();

    for(int i=0; i<=tour; i++){
        tampon = 0. ;

        for (int j=0; j<i; j++){
            tampon += invest[j];
        }
        invest_cumule.push_back(tampon);
    }
    return invest_cumule;

}

double Historique::get_investissement_max(){
    QVector <double> invest = get_investissement_cumule();

    double max= 0.;

    if(tour==0){
        max = 0.;
    }
    else{

        max = *std::max_element(invest.begin(),invest.end());

    }

   return max;

}

double Historique::max_cout(){
    QVector <double> maxs;
    QVector <double> fixe = get_cout_fixe();
    maxs.push_back(*std::max_element(fixe.begin(), fixe.end()));
    QVector <double> variable = get_cout_variable();
    maxs.push_back(*std::max_element(variable.begin(), variable.end()));
    QVector <double> invest = get_investissement();
    maxs.push_back(*std::max_element(invest.begin(), invest.end()));

    return *std::max_element(maxs.begin(), maxs.end());
}

QVector <double> Historique::get_production(){
    QVector <double> prod;
    for (int i = 0; i <= tour; i++){
        prod.push_back(productions[i][0]);
    }
    return prod;
}

QVector <double> Historique::get_vente(){
    QVector <double> vente;
    for (int i = 0; i <= tour; i++){
        vente.push_back(ventes[i][0]);
    }
    return vente;
}

QVector <double> Historique::get_invendu(){
    QVector <double> invendu;
    QVector <double> vente = get_vente();
    for (int i=0; i<=tour; i++){
        invendu.push_back(productions[i][0] + stocks[i][0] - vente[i]);
    }
    return invendu;
}

double Historique::max_vente_invendu(){
    QVector <double> vente = get_vente();
    QVector <double> invendu = get_invendu();

    double max_vente = vente[0];
    double max_invendu = invendu[0];


    for(int i=0; i <= tour; i++){
        if (vente[i] > max_vente){
            max_vente = vente[i];
        }
        if (invendu[i] > max_invendu){
            max_invendu = invendu[i];
        }
    }

    if (max_vente > max_invendu){
        return max_vente;
    } else{
        return max_invendu;
    }

}

QVector <double> Historique::get_prix_de_vente(){
    QVector <double> prix_de_vente_vec;

    for(int i=0; i<=tour; i++){
        prix_de_vente_vec.push_back(prix_de_vente[i][0]);
    }
    return prix_de_vente_vec;
}

QVector <double> Historique::get_prix_de_vente_moyen(){
    QVector <double> prix_de_vente_moyen_vec;

    for(int i=0; i<=tour; i++){
        prix_de_vente_moyen_vec.push_back(prix_de_vente_moyen[i]);
    }
    return prix_de_vente_moyen_vec;
}

