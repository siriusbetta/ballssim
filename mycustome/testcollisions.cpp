#include "testcollisions.h"
#include "../collisions.h"
#include "../coordiantescontainer.h"

Testcollisions::Testcollisions(QObject *parent): QObject(parent)
{

}

void Testcollisions::testIsPlaceCompareOtherBalls()
{
    Coordinates c1(50, 50);
    Coordinates c2(100, 100);
    Coordinates c3(150, 150);
    Coordinates c4(200, 200);

    CoordiantesContainer::Instance().setCoordinates(1, c1);
    CoordiantesContainer::Instance().setCoordinates(2, c2);
    CoordiantesContainer::Instance().setCoordinates(3, c3);
    CoordiantesContainer::Instance().setCoordinates(4, c4);

    QFETCH(int, x);
    QFETCH(int, y);
    QFETCH(bool, expected);
    Coordinates c(x, y);
    QCOMPARE(Collisions::isPlaceCompareOtherBalls(c), expected);
}

void Testcollisions::testIsPlaceCompareOtherBalls_data()
{
    QTest::addColumn<int>("x");
    QTest::addColumn<int>("y");
    QTest::addColumn<bool>("expected");
    QTest::newRow("other balls coordianate 1") << 300 << 300 << true;
    QTest::newRow("other balss coordianate 2") << 250 << 250 << true;
    QTest::newRow("other balss coordianate 3") << 130 << 100 << false;
    QTest::newRow("oteh balls coordianate 4") << 100 << 130 << false;
    QTest::newRow("other balls coordianate 5") << 100 << 100 << false;
}

void Testcollisions::testIsAvaiblePos()
{
    Coordinates c1(50, 50);
    Coordinates c2(100, 100);
    Coordinates c3(150, 150);
    Coordinates c4(200, 200);

    CoordiantesContainer::Instance().setCoordinates(1, c1);
    CoordiantesContainer::Instance().setCoordinates(2, c2);
    CoordiantesContainer::Instance().setCoordinates(3, c3);
    CoordiantesContainer::Instance().setCoordinates(4, c4);

    QFETCH(int, x);
    QFETCH(int, y);
    QFETCH(bool, expected);
    Coordinates c(x, y);
    QCOMPARE(Collisions::isAvaiblePos(c), expected);
}

void Testcollisions::testIsAvaiblePos_data()
{
    QTest::addColumn<int>("x");
    QTest::addColumn<int>("y");
    QTest::addColumn<bool>("expected");
    QTest::newRow("other balls coordianate 1") << 300 << 300 << true;
    QTest::newRow("other balss coordianate 2") << 250 << 250 << true;
    QTest::newRow("other balss coordianate 3") << 130 << 100 << false;
    QTest::newRow("oteh balls coordianate 4") << 100 << 130 << false;
    QTest::newRow("other balls coordianate 5") << 100 << 100 << false;
    QTest::newRow("wall coordianate 1") << 100 << 100 << false;
    QTest::newRow("wall coordianate 2") << 220 << 300 << true;
    QTest::newRow("wall coordianate 3") << 10 << 100 << false;
    QTest::newRow("wall coordianate 4") << 100 << 10 << false;
}

void Testcollisions::testIsCoordinateLayInTheBall()
{
    QFETCH(int, x1);
    QFETCH(int, y1);
    QFETCH(int, x2);
    QFETCH(int, y2);
    QFETCH(bool, expected);
    Coordinates c1(x1, y1);
    Coordinates c2(x2, y2);
    QCOMPARE(Collisions::isCoordinateLayInTheBall(c1, c2), expected);
}

void Testcollisions::testIsCoordinateLayInTheBall_data()
{
    QTest::addColumn<int>("x1");
    QTest::addColumn<int>("y1");
    QTest::addColumn<int>("x2");
    QTest::addColumn<int>("y2");
    QTest::addColumn<bool>("expected");
    QTest::newRow("ball match with ball coordianate 1") << 50 << 50 << 50 << 50 << true;
    QTest::newRow("ball match with ball coordianate 2") << 100 << 50 << 105 << 55 << true;
    QTest::newRow("ball match with ball coordianate 3") << 300 << 300 << 100 << 100 << false;
    QTest::newRow("ball match with ball coordianate 4") << 250 << 150 << 50 << 200 << false;
    QTest::newRow("ball match with ball coordianate 5") << 100 << 100 << 105 << 100 << true;
}

void Testcollisions::testChechLengthToTheWalls_data()
{
    QTest::addColumn<int>("x");
    QTest::addColumn<int>("y");
    QTest::addColumn<bool>("expected");

    QTest::newRow("wall coordianate 1") << 100 << 100 << true;
    QTest::newRow("wall coordianate 2") << 220 << 300 << true;
    QTest::newRow("wall coordianate 3") << 10 << 100 << false;
    QTest::newRow("wall coordianate 4") << 100 << 10 << false;
}

void Testcollisions::testChechLengthToTheWalls()
{
    QFETCH(int, x);
    QFETCH(int, y);
    QFETCH(bool, expected);
    Coordinates c(x, y);
    QCOMPARE(Collisions::isPlaceCompareWalls(c), expected);
}

void Testcollisions::compareTwoCoordinates_data()
{
    //QCOMPARE(cont.compareTwoCoordiantes(&c1, &c2), true);

    QTest::addColumn<int>("x1");
    QTest::addColumn<int>("y1");
    QTest::addColumn<int>("x2");
    QTest::addColumn<int>("y2");
    QTest::addColumn<bool>("expected");
    QTest::newRow("coordianate 1") << 100 << 100 << 150 << 100 << true;
    QTest::newRow("coordianate 2") << 100 << 100 << 50 << 100 << true;
    QTest::newRow("coordianate 3") << 100 << 100 << 100 << 50 << true;
    QTest::newRow("coordianate 4") << 100 << 100 << 100 << 150 << true;
    QTest::newRow("coordianate 5") << 100 << 100 << 100 << 100 << false;

    QTest::newRow("coordianate 6") << 150 << 150 << 300 << 300 << true;

}

void Testcollisions::compareTwoCoordinates()
{
    QFETCH(int, x1);
    QFETCH(int, y1);
    QFETCH(int, x2);
    QFETCH(int, y2);
    QFETCH(bool, expected);
    Coordinates c1(x1, y1);
    Coordinates c2(x2, y2);
    QCOMPARE(Collisions::hasEnoughPlaceBetweenTwoBalls(c1, c2), expected);
}

