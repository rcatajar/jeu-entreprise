#ifndef TESTS_ENTITE_H
#define TESTS_ENTITE_H

#include <QString>
#include <QtTest>

#include "../jeu-entreprise/objet.h"
#include "../jeu-entreprise/entite.h"

class TestsEntite : public QObject
{
    Q_OBJECT

public:
    TestsEntite();

private Q_SLOTS:
    void init(); // appelé automatiquement avant chaque test
    void test_constructeur_set_nom();
    void test_constructeur_set_tresorerie();
    void test_tresorerie();
    void test_ajouter_au_stock();
    void test_retirer_au_stock();

private:
    Entite* entite;
};

#endif // TESTS_ENTITE_H
