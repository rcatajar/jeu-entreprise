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

private:
    Entreprise* entreprise;
};

#endif // TESTS_ENTREPRISE_H
