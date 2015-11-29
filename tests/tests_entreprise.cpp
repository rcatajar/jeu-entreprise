#include <QString>
#include <QtTest>
#include <vector>

#include "../jeu-entreprise/objet.h"
#include "../jeu-entreprise/entreprise.h"
#include "tests_entreprise.h"

using namespace std;

TestsEntreprise::TestsEntreprise()
{
}

// Initialise chaque test en creant une entite de test
void TestsEntreprise::init(){
    entreprise = new Entreprise("test", 42, false);
}
