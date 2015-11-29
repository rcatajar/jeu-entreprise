#include <QString>
#include <QtTest>
#include <vector>

#include "../jeu-entreprise/objet.h"
#include "../jeu-entreprise/client.h"
#include "../jeu-entreprise/entreprise.h"
#include "tests_client.h"

using namespace std;

TestsClient::TestsClient()
{
}

// Initialise chaque test en creant une entite de test
void TestsClient::init(){
    client = new Client("test", 0);
}

void TestsClient::test_constructeur_set_revenu_valide(){
    QVERIFY(client->get_revenu() < 100);
    QVERIFY(client->get_revenu() > 0);
}

void TestsClient::test_quantite_a_acheter(){
    // Pas d'objet, le client veux en acheter un
    QVERIFY(client->quantite_a_acheter() == 1);

    // On ajoute un objet au client, il ne veux plus en acheter
    client->ajouter_au_stock(new Objet(client));
    QVERIFY(client->quantite_a_acheter() == 0);
}

void TestsClient::test_achat_ok(){
    // On verifie que si on lui propose un objet moins cher que sa tresorerie, le client l'achete
    Entreprise* entreprise = new Entreprise("Test", 0, false);
    Objet* objet = new Objet(entreprise);
    entreprise->ajouter_au_stock(objet);
    vector <Objet*> stock_attendu;
    stock_attendu.push_back(objet);

    client->set_tresorerie(1000);
    entreprise->set_prix_de_vente(100);

    client->achat(stock_attendu);
    QVERIFY(client->get_stock() == stock_attendu);
    QVERIFY(objet->get_proprietaire() == client);
    QVERIFY(client->get_tresorerie() == 900);
}

void TestsClient::test_achat_objet_trop_cher(){
    // On verifie que si on lui propose un objet plus cher que sa tresorerie, le client n'achete rien
    Entreprise* entreprise = new Entreprise("Test", 0, false);
    Objet* objet = new Objet(entreprise);
    entreprise->ajouter_au_stock(objet);
    vector <Objet*> stock_attendu;

    client->set_tresorerie(1000);
    entreprise->set_prix_de_vente(10000);

    client->achat(stock_attendu);
    QVERIFY(client->get_stock() == stock_attendu);
    QVERIFY(objet->get_proprietaire() == entreprise);
    QVERIFY(client->get_tresorerie() == 1000);
}

void TestsClient::test_phase_de_revenu(){
    int treso = client->get_tresorerie();
    int revenu = client->get_revenu();

    client->phase_de_revenu();
    QVERIFY(client->get_tresorerie() == treso + revenu);
}
