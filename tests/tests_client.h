#ifndef TESTS_CLIENT_H
#define TESTS_CLIENT_H

#include <QString>
#include <QtTest>

#include "../jeu-entreprise/client.h"

class TestsClient : public QObject
{
    Q_OBJECT

public:
    TestsClient();

private Q_SLOTS:
    void init(); // appelé automatiquement avant chaque test
    void test_constructeur_set_revenu_valide();
    void test_quantite_a_acheter();
    void test_achat_ok();
    void test_achat_objet_trop_cher();
    void test_phase_de_revenu();

private:
    Client* client;
};

#endif // TESTS_CLIENT_H
