/* Classe encapsulant l'historique des différentes valeurs clés du jeu
 * pour qu'on puisse tracer des jolies graphes pleins de données cools
 *
 * Pour le jeu:
 * - tour en cours
 * - tour max
 * Pour le marché:
 * - nombre total d'objets en vente
 * - prix de vente moyen
 *
 * Pour les Entreprises:
 *  - nom joueur
 * - nombre d'IA
 * - stock au début de chaque tour
 * - prix de vente
 * - fabrication pour le tour
 * - investissement en recherche
 * - qualité marginale
 * - nombre de vente sur le tour
 * - trésorerie
 * - objets détruits en gestion des stocks
 *
 * Pour les Clients:
 *  - nombre de clients total
 *  - nombre de clients voulant acheter ce tour
 *  - nombre d'objets achetés total ce tour
 *  - nombre total d'objets détruits
 */

#ifndef HISTORIQUE_H
#define HISTORIQUE_H

#include <vector>
#include <QString>
#include <QVector>


class Historique
{
public:
    Historique(int, int, QString, int, int, int, int);

    // J'ai mis toute les variables en public pour qu'on puisse les modfier directement
    // (c'est pas top mais c'est plus rapide a faire)

    // Jeu
    int tour;
    int tour_max;

    // Marché
    std::vector <int> objets_en_vente;
    std::vector <int> prix_de_vente_moyen;

    // Entreprise
    int cout_fixe;
    int cout_variable;
    QString nom_joueur;
    int nombre_ias;
    std::vector <std::vector <int>> stocks;
    std::vector <std::vector <int>> prix_de_vente;
    std::vector <std::vector <int>> productions;
    std::vector <std::vector <int>> investissements_recherche;
    std::vector <std::vector <int>> qualites_marginale;
    std::vector <std::vector <int>> ventes;
    std::vector <std::vector <int>> tresoreries;
    std::vector <std::vector <int>> objets_detruits;

    // Client
    int nombre_clients;
    std::vector <int> nombre_acheteurs;
    std::vector <int> objets_achetes;
    std::vector <int> objets_detruits_client;

    // Pour les graphes
    QVector <double> get_ticks();
    QVector <QString> get_labels();
    QVector <double> get_tresorerie();
    QVector <double> get_ca();
    QVector <double> get_cout_fixe();
    QVector <double> get_cout_variable();
    QVector <double> get_investissement();
    double max_cout();
};

#endif // HISTORIQUE_H
