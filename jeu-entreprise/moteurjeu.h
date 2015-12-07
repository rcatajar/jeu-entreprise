// Le moteur du jeu
// Gère la gestion des tours et des différentes phases du jeu

#ifndef MOTEURJEU_H
#define MOTEURJEU_H

#include <vector>
#include "QString"

#include "entreprise.h"
#include "objet.h"
#include "client.h"
#include "historique.h"


class MoteurJeu
{
protected:
    std::vector <Client*> clients;
    int tour;
    int tour_max;
    QString nom_joueur;

public:
    std::vector <Entreprise*> entreprises;
    Historique* historique;
    MoteurJeu(int, int, int, int, int, QString);
    void creation_entreprises_initiales(int, int);
    void creation_clients_initiaux(int, int);
    void creation_objets_initiaux(int);
    void phase_de_production(int);
    void phase_de_marketing(int);
    void phase_de_vente();
    void phase_de_recherche(int);
    void phase_de_revenu();
    std::vector <Objet*> get_objets_marche();
    void phase_de_gestion_des_stocks();
    Entreprise* get_gagnant();
    void run_tour(int, int, int);

    // Les méthodes utilisées pour remplir l'historique
    void set_historique_intiale();
    void set_historique_objets_en_vente();
    void set_historique_stocks();
    void set_historique_recherche();
    void set_historique_tresoreries();
    void set_historique_acheteurs();
    void set_historique_productions();
    void set_historique_prix_de_vente();
    void set_historique_qualite();

};

#endif // MOTEURJEU_H
