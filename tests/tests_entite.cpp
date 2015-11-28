#include <QString>
#include <QtTest>
#include <vector>

#include "../jeu-entreprise/objet.h"
#include "../jeu-entreprise/entite.h"
#include "tests_entite.h"

using namespace std;

TestsEntite::TestsEntite()
{
}

// Initialise chaque test en creant une entite de test
void TestsEntite::init(){
    entite = new Entite("test", 42);
}

void TestsEntite::test_constructeur_set_nom(){
    QVERIFY(entite->get_nom() == "test");
}

void TestsEntite::test_constructeur_set_tresorerie(){
    QVERIFY(entite->get_tresorerie() == 42);
}

void TestsEntite::test_tresorerie(){
    entite->set_tresorerie(10000);
    QVERIFY(entite->get_tresorerie() == 10000);
}

void TestsEntite::test_ajouter_au_stock(){
    vector <Objet*> stock_attendu;
    Entite* proprio = new Entite("test", 1);
    Objet* objet = new Objet(proprio);
    stock_attendu.push_back(objet);

    entite->ajouter_au_stock(objet);
    // On teste que l'objet a bien ete ajoute au stock
    // puis que le nouveau proprio de l'objet est notre entite
    QVERIFY(entite->get_stock() == stock_attendu);
    QVERIFY(objet->get_proprietaire() == entite);
}

void TestsEntite::test_retirer_au_stock(){
    // On construit un stock fictif
    Objet* objet = new Objet(entite);
    entite->ajouter_au_stock(objet);
    Objet* objet2 = new Objet(entite);
    entite-> ajouter_au_stock(objet2);
    Objet* objet3 = new Objet(entite);

    vector <Objet*> stock_attendu;
    stock_attendu.push_back(objet);

    entite->retirer_au_stock(objet2);
    // On teste que l'objet a bien été viré du stock
    QVERIFY(entite->get_stock() == stock_attendu);

    // On teste que rien ne change si on essaie de
    // retirer un objet qui n'est pas dans le stock
    entite->retirer_au_stock(objet3);
    QVERIFY(entite->get_stock() == stock_attendu);
}
