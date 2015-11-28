#include <QString>
#include <QtTest>

#include "tests_entite.cpp"
#include "tests_objet.cpp"


// Le main run les tests de chacune des classes de tests
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
   return status;
}
