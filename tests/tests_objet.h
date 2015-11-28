#ifndef TESTS_OBJET_H
#define TESTS_OBJET_H

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
    void test_constructeur_qualite_aleatoire_valide();
    void test_constructeur_qualite_fixe();
    void test_qualite();
    void test_proprietaire();

private:
    Objet* objet;
    Entite* entite;
};

#endif // TESTS_OBJET_H
