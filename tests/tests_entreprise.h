#ifndef TESTS_ENTREPRISE_H
#define TESTS_ENTREPRISE_H

#include <QString>
#include <QtTest>

#include "../jeu-entreprise/entreprise.h"

class TestsEntreprise : public QObject
{
    Q_OBJECT

public:
    TestsEntreprise();

private Q_SLOTS:
    void init(); // appelé automatiquement avant chaque test
    void test_constructeur_set_ia();
    void test_prix_de_vente();
    void test_cout_fixe();
    void test_cout_variable();
    void test_investissement_realise();
    void test_produire();
    void test_investir();
    void test_vente_objet();
    void test_phase_de_marketing_ia();
    void test_phase_de_production_ia();
    void test_phase_de_recherche_ia();



private:
    Entreprise* entreprise;
};

#endif // TESTS_ENTREPRISE_H
