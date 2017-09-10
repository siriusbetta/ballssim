#include "testcoordinates.h"

TestCoordinates::TestCoordinates(QObject *parent) :
    QObject(parent)
{
}

void TestCoordinates::test_x()
{
    Coordinates c(6, 5);
    QCOMPARE(c.m_x, 6);
    QCOMPARE(c.getX(), 6);
}
void TestCoordinates::test_y()
{
    Coordinates c(6, 5);
    QCOMPARE(c.m_y, 5);
    QCOMPARE(c.getY(), 5);
}

void TestCoordinates::test_length_calculations()
{
    Coordinates c1(6, 5);
    Coordinates c2(6, 5);
    QCOMPARE(Coordinates::lengthBetweenTwoPoints(c1, c2), 0);

    Coordinates c3(2, 2);
    Coordinates c4(1, 1);
    QCOMPARE(Coordinates::lengthBetweenTwoPoints(c3, c4), 1);

    Coordinates c5(25, 15);
    Coordinates c6(50, 75);
    QCOMPARE(Coordinates::lengthBetweenTwoPoints(c5, c6), 65);
}
