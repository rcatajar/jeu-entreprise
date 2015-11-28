#include <QString>
#include <QtTest>

class TestsObjet : public QObject
{
    Q_OBJECT

public:
    TestsObjet();

private Q_SLOTS:
    void testObjet();
};

TestsObjet::TestsObjet()
{
}

void TestsObjet::testObjet()
{
    QVERIFY2(true, "Failure");
}




// Indique a QtTest qu'il faut run ces tests
QTEST_APPLESS_MAIN(TestsObjet)

#include "tests_objet.moc"
