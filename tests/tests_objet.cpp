#include <QString>
#include <QtTest>

#include "tests_objet.h"
#include "../jeu-entreprise/objet.h"
#include "../jeu-entreprise/entite.h"


TestsObjet::TestsObjet(){}

// Initialise chaque test en creant un objet et son proprietaire
void TestsObjet::init(){
    entite = new Entite("test", 0);
    objet = new Objet(entite);
}

void TestsObjet::test_constructeur_set_proprietaire()
{
    QVERIFY(objet->get_proprietaire() == entite);
}

void TestsObjet::test_constructeur_qualite_aleatoire_valide()
{
    QVERIFY(objet->get_qualite() < 100);
    QVERIFY(objet->get_qualite() > 0);
}

void TestsObjet::test_constructeur_qualite_fixe(){
    Objet* objet2 = new Objet(entite, 42);
    QVERIFY(objet2->get_qualite() == 42);
}

void TestsObjet::test_qualite(){
    objet->set_qualite(42);
    QVERIFY(objet->get_qualite() == 42);
}

void TestsObjet::test_proprietaire(){
    Entite* proprio = new Entite("kikoo", 123);
    objet->set_proprietaire(proprio);
    QVERIFY(objet->get_proprietaire() == proprio);
}
