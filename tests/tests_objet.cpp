#include <QString>
#include <QtTest>

#include "../jeu-entreprise/objet.h"
#include "../jeu-entreprise/entite.h"

class TestsObjet : public QObject
{
    Q_OBJECT

public:
    TestsObjet();

private Q_SLOTS:
    void init(); // appelé automatiquement avant chaque test
    void test_constructeur_set_proprietaire();
    void test_constructeur_set_qualite_valide();
    void test_qualite();
    void test_proprietaire();

private:
    Objet* objet;
    Entite* entite;
};

TestsObjet::TestsObjet()
{
}

// Initialise chaque test en creant un objet et son proprietaire
void TestsObjet::init(){
    entite = new Entite("test", 0);
    objet = new Objet(entite);
}

void TestsObjet::test_constructeur_set_proprietaire()
{
    QVERIFY(objet->get_proprietaire() == entite);
}

void TestsObjet::test_constructeur_set_qualite_valide()
{
    QVERIFY(objet->get_qualite() < 100);
    QVERIFY(objet->get_qualite() > 0);
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

// Indique a QtTest qu'il faut run ces tests
QTEST_APPLESS_MAIN(TestsObjet)

#include "tests_objet.moc"
