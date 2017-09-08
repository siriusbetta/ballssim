#include "testcoordinatescontainer.h"
#include "../coordinates.h"
#include <map>

TestCoordinatescontainer::TestCoordinatescontainer(QObject *parent) :
    QObject(parent)
{
}

void TestCoordinatescontainer::compareTwoCoordinates_data()
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

void TestCoordinatescontainer::compareTwoCoordinates()
{
    CoordiantesContainer cont;
    QFETCH(int, x1);
    QFETCH(int, y1);
    QFETCH(int, x2);
    QFETCH(int, y2);
    QFETCH(bool, expected);
    Coordinates c1(x1, y1);
    Coordinates c2(x2, y2);
    QCOMPARE(cont.hasEnoughPlaceBetweenTwoBalls(&c1, &c2), expected);
}

void TestCoordinatescontainer::testChechLengthToTheWalls_data()
{
    QTest::addColumn<int>("x");
    QTest::addColumn<int>("y");
    QTest::addColumn<bool>("expected");

    QTest::newRow("wall coordianate 1") << 100 << 100 << true;
    QTest::newRow("wall coordianate 2") << 220 << 300 << true;
    QTest::newRow("wall coordianate 3") << 10 << 100 << false;
    QTest::newRow("wall coordianate 4") << 100 << 10 << false;
}

void TestCoordinatescontainer::testChechLengthToTheWalls()
{
    CoordiantesContainer cont;
    QFETCH(int, x);
    QFETCH(int, y);
    QFETCH(bool, expected);
    Coordinates c(x, y);
    QCOMPARE(cont.isPlaceCompareWalls(&c), expected);
}

void TestCoordinatescontainer::testCoordinatsInsertion()
{
    CoordiantesContainer cont;
    Coordinates c1(1, 1);
    Coordinates c2(2, 2);
    Coordinates c3(3, 3);
    Coordinates c4(4, 4);

    cont.setCoordinates(1, &c1);
    QCOMPARE(cont.length(), 1);

    cont.setCoordinates(2, &c2);
    QCOMPARE(cont.length(), 2);

    cont.setCoordinates(3, &c3);
    QCOMPARE(cont.length(), 3);

    cont.setCoordinates(4, &c4);
    QCOMPARE(cont.length(), 4);

}

void TestCoordinatescontainer::testCoordinatsGetting()
{
    CoordiantesContainer cont;
    Coordinates c1(1, 1);
    Coordinates c2(2, 2);
    Coordinates c3(3, 3);
    Coordinates c4(4, 4);

    cont.setCoordinates(1, &c1);
    Coordinates *c = cont.getCoordinates(1);
    QCOMPARE(c -> getX(), 1);

    cont.setCoordinates(2, &c2);
    c = cont.getCoordinates(2);
    QCOMPARE(c -> getX(), 2);

    cont.setCoordinates(3, &c3);
    c = cont.getCoordinates(3);
    QCOMPARE(c -> getX(), 3);

    cont.setCoordinates(4, &c4);
    c = cont.getCoordinates(4);
    QCOMPARE(c -> getX(), 4);

    cont.setCoordinates(1, &c1);
    c = cont.getCoordinates(1);
    QCOMPARE(c -> getY(), 1);

    cont.setCoordinates(2, &c2);
    c = cont.getCoordinates(2);
    QCOMPARE(c -> getY(), 2);

    cont.setCoordinates(3, &c3);
    c = cont.getCoordinates(3);
    QCOMPARE(c -> getY(), 3);

    cont.setCoordinates(4, &c4);
    c = cont.getCoordinates(4);
    QCOMPARE(c -> getY(), 4);

    QCOMPARE(cont.length(), 4);
}

void TestCoordinatescontainer::testIsPlaceCompareOtherBalls()
{
    CoordiantesContainer cont;
    Coordinates c1(50, 50);
    Coordinates c2(100, 100);
    Coordinates c3(150, 150);
    Coordinates c4(200, 200);

    cont.setCoordinates(1, &c1);
    cont.setCoordinates(2, &c2);
    cont.setCoordinates(3, &c3);
    cont.setCoordinates(4, &c4);

    QFETCH(int, x);
    QFETCH(int, y);
    QFETCH(bool, expected);
    Coordinates c(x, y);
    QCOMPARE(cont.isPlaceCompareOtherBalls(&c), expected);
}

void TestCoordinatescontainer::testIsPlaceCompareOtherBalls_data()
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

void TestCoordinatescontainer::testIsAvaiblePos()
{
    CoordiantesContainer cont;
    Coordinates c1(50, 50);
    Coordinates c2(100, 100);
    Coordinates c3(150, 150);
    Coordinates c4(200, 200);

    cont.setCoordinates(1, &c1);
    cont.setCoordinates(2, &c2);
    cont.setCoordinates(3, &c3);
    cont.setCoordinates(4, &c4);

    QFETCH(int, x);
    QFETCH(int, y);
    QFETCH(bool, expected);
    Coordinates c(x, y);
    QCOMPARE(cont.isAvaiblePos(&c), expected);
}

void TestCoordinatescontainer::testIsAvaiblePos_data()
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

void TestCoordinatescontainer::testIsCoordinateLayInTheBall()
{
    CoordiantesContainer cont;
    QFETCH(int, x1);
    QFETCH(int, y1);
    QFETCH(int, x2);
    QFETCH(int, y2);
    QFETCH(bool, expected);
    Coordinates c1(x1, y1);
    Coordinates c2(x2, y2);
    QCOMPARE(cont.isCoordinateLayInTheBall(&c1, &c2), expected);
}

void TestCoordinatescontainer::testIsCoordinateLayInTheBall_data()
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
}

void TestCoordinatescontainer::testRemoveItem()
{
    CoordiantesContainer cont;
    Coordinates c1(100, 100);
    Coordinates c2(150, 200);
    Coordinates c3(300, 350);
    Coordinates c4(400, 200);


    cont.setCoordinates(1, &c1);
    cont.setCoordinates(2, &c2);
    cont.setCoordinates(3, &c3);
    cont.setCoordinates(4, &c4);

    QCOMPARE(cont.length(), 4);
    Coordinates *c = new Coordinates(105, 100);
    cont.removeItem(c);
    QCOMPARE(cont.length(), 3);
}

void TestCoordinatescontainer::testRemoveItem_data()
{

}

void TestCoordinatescontainer::testFindBallByCoordinates()
{
    CoordiantesContainer cont;
    Coordinates c1(100, 100);
    Coordinates c2(150, 200);
    Coordinates c3(300, 350);
    Coordinates c4(400, 200);


    cont.setCoordinates(1, &c1);
    cont.setCoordinates(2, &c2);
    cont.setCoordinates(3, &c3);
    cont.setCoordinates(4, &c4);

    QCOMPARE(cont.length(), 4);
    Coordinates *c = new Coordinates(105, 100);
    QCOMPARE( cont.findBallByCoordinates(c), 1);

    c = new Coordinates(300, 350);
    QCOMPARE( cont.findBallByCoordinates(c), 3);

    c = new Coordinates(480, 380);
    QCOMPARE( cont.findBallByCoordinates(c), -1);
}

void TestCoordinatescontainer::testFindBallByCoordinates_data()
{

}
