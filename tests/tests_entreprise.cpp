#include <QString>
#include <QtTest>
#include <vector>
#include <iostream>

#include "../jeu-entreprise/objet.h"
#include "../jeu-entreprise/entreprise.h"
#include "tests_entreprise.h"

using namespace std;

TestsEntreprise::TestsEntreprise()
{
}

// Initialise chaque test en creant une entreprise (IA) à tester
void TestsEntreprise::init(){
    entreprise = new Entreprise("test", 20000, true);
}

void TestsEntreprise::test_constructeur_set_ia(){
    Entreprise* e = new Entreprise("test", 0, true);
    QVERIFY(e->is_ia() == true);

    Entreprise* e2 = new Entreprise("test", 0, false);
    QVERIFY(e2->is_ia() == false);
}

void TestsEntreprise::test_constructeur_set_qualite_marginale(){
    QVERIFY(entreprise->get_qualite_marginale() == 0);
}

void TestsEntreprise::test_constructeur_set_max_recherche(){
    QVERIFY(entreprise->recherche_max_atteinte() == false);
}

void TestsEntreprise::test_prix_de_vente(){
    entreprise->set_prix_de_vente(42);
    QVERIFY(entreprise->get_prix_de_vente() == 42);
}

void TestsEntreprise::test_cout_fixe(){
    entreprise->set_cout_fixe(42);
    QVERIFY(entreprise->get_cout_fixe() == 42);
}

void TestsEntreprise::test_cout_variable(){
    entreprise->set_cout_variable(42);
    QVERIFY(entreprise->get_cout_variable() == 42);
}

void TestsEntreprise::test_investissement_realise(){
    // On check qu'a la creation, l'investissement est 0
    QVERIFY(entreprise->get_investissement_realise() == 0);
}

void TestsEntreprise::test_produire_0_objet(){
    // On test que meme si on produit 0 objets:
    //  - elle paye quand meme les frais fixes
    //  - son stock ne change pas
    int cout_fixe = entreprise->get_cout_fixe();
    int treso = entreprise->get_tresorerie();
    vector <Objet*> stock_attendu;

    entreprise->produire(0);
    QVERIFY(entreprise->get_tresorerie() == treso - cout_fixe);
    QVERIFY(entreprise->get_stock() == stock_attendu);
}

void TestsEntreprise::test_produire(){
    // On test que si on produit n objets:
    //  - la tréso diminue de fixe + n * variable
    //  - le stock augmente de n objets
    //  - l'entreprise est proprietaire de ces n objets
    int cout_fixe = entreprise->get_cout_fixe();
    int cout_variable = entreprise->get_cout_variable();
    int treso = entreprise->get_tresorerie();

    entreprise->produire(3);
    QVERIFY(entreprise->get_tresorerie() == treso - cout_fixe - 3 * cout_variable);
    vector <Objet*> stock = entreprise->get_stock();
    QVERIFY(stock.size() == 3);
    for (int i=0; i < stock.size(); i++){
        QVERIFY(stock[i]->get_proprietaire() == entreprise);
    }
}

void TestsEntreprise::test_investir_pas_de_changement_de_seuil(){
    entreprise->investir(10);
    QVERIFY(entreprise->recherche_max_atteinte() == false);
    QVERIFY(entreprise->get_qualite_marginale() == 0);
}

void TestsEntreprise::test_investir_saut_de_seuil(){
    entreprise->investir(1000);
    cout << entreprise->get_qualite_marginale();
    QVERIFY(entreprise->get_qualite_marginale() == 1);
    entreprise->investir(2000);
    QVERIFY(entreprise->get_qualite_marginale() == 3);
    QVERIFY(entreprise->recherche_max_atteinte() == false);
}

void TestsEntreprise::test_investir_recherche_maximale(){
    entreprise->investir(15000);
    QVERIFY(entreprise->get_qualite_marginale());
}

void TestsEntreprise::test_investir_set_investissement_realise(){
    entreprise->investir(200);
    QVERIFY(entreprise->get_investissement_realise() == 200);
    entreprise->investir(42);
    QVERIFY(entreprise->get_investissement_realise() == 242);
}

void TestsEntreprise::test_investir_set_tresorerie(){
    int treso = entreprise->get_tresorerie();
    entreprise->investir(42);
    QVERIFY(entreprise->get_tresorerie() == treso - 42);
}

void TestsEntreprise::test_vente_objet(){
    Objet* objet = new Objet(entreprise);
    entreprise->ajouter_au_stock(objet);
    int treso = entreprise->get_tresorerie();
    entreprise->set_prix_de_vente(42);
    vector <Objet*> stock_attendu;

    entreprise->vente_objet(objet);
    QVERIFY(entreprise->get_tresorerie() == treso + 42);
    QVERIFY(entreprise->get_stock() == stock_attendu);
}

void TestsEntreprise::test_phase_de_marketing_ia(){
    // On test que durant la phase de marketing l'IA set son prix de vente correctement
    // On crée un stock a l'entreprise de test
    for (int i=0; i < 10; i++){
        entreprise->ajouter_au_stock(new Objet(entreprise));
    }
    entreprise->phase_de_marketing(10);
    QVERIFY(entreprise->get_prix_de_vente() > 0);
}

void TestsEntreprise::test_phase_de_marketing_joueur(){
    Entreprise* e = new Entreprise("Test", 1000, false);
    e->phase_de_marketing(100);
    QVERIFY(e->get_prix_de_vente() == 100);
}

void TestsEntreprise::test_phase_de_production_ia(){
    // On test que durant la phase de production l'IA produit un nombre correct d'objets
    // Le nombre d'objets à produire dépend de: tresorerie, cout fixe, cout variable
    int tresorerie = entreprise->get_tresorerie();
    int cout_fixe = entreprise->get_cout_fixe();
    int cout_variable = entreprise->get_cout_variable();
    int production_attendu = (tresorerie - cout_fixe) / (2 * cout_variable);

    entreprise->phase_de_production(100);
    QVERIFY(entreprise->get_stock().size() <= production_attendu);
}

void TestsEntreprise::test_phase_de_production_joueur(){
    Entreprise* e = new Entreprise("Test", 1000, false);
    e->phase_de_production(10);
    QVERIFY(e->get_stock().size() == 10);
}

void TestsEntreprise::test_phase_de_recherche_ia(){
    entreprise->phase_de_recherche(100);
    // L'IA n'invesit jamais plus de la moitié de sa tréso
    QVERIFY(entreprise->get_investissement_realise() <= entreprise->get_tresorerie() / 2);
}

void TestsEntreprise::test_phase_de_recherche_joueur(){
    Entreprise* e = new Entreprise("test", 1000, false);
    e->phase_de_recherche(100);
    QVERIFY(e->get_investissement_realise() == 100);
}

