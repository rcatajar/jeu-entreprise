#include <QString>
#include <QtTest>

#include "tests_entite.h"
#include "tests_objet.h"
#include "tests_client.h"
#include "tests_entreprise.h"

// Le main run les tests de chacune des classes de tests
// cf http://www.davideling.it/2014/01/qtest-multiple-unit-test-classes/
int main(int argc, char** argv)
{
   int status = 0;
   {
        TestsEntite tc;
        status |= QTest::qExec(&tc, argc, argv);
   }
   {
        TestsObjet tc;
        status |= QTest::qExec(&tc, argc, argv);
   }
   {
        TestsClient tc;
        status |= QTest::qExec(&tc, argc, argv);
   }
   {
       TestsEntreprise tc;
       status |= QTest::qExec(&tc, argc, argv);
   }

   system("pause");

   return status;
}
