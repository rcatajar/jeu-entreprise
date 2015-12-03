// Le moteur du jeu
// Gère la gestion des tours et des différentes phases du jeu

#ifndef MOTEURJEU_H
#define MOTEURJEU_H

#include <vector>

#include "entreprise.h"
#include "objet.h"
#include "client.h"
#include "historique.h"

class MoteurJeu
{
protected:
    Historique* historique;
    std::vector <Entreprise*> entreprises;
    std::vector <Client*> clients;
    int tour;
    int tour_max;
public:
    MoteurJeu(int, int, int, int, int);
    void creation_entreprises_initiales(int, int);
    void creation_clients_initiaux(int, int);
    void creation_objets_initiaux(int);
    void phase_de_production();
    void phase_de_marketing();
    void phase_de_vente();
    void phase_de_recherche();
    void phase_de_revenu();
    std::vector <Objet*> get_objets_marche();
    void phase_de_gestion_des_stocks();
    Entreprise* get_gagnant();
    void run_tour();
    Entreprise* run();
};

#endif // MOTEURJEU_H
