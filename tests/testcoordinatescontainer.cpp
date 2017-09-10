#include "testcoordinatescontainer.h"
#include "../coordinates.h"
#include <map>
#include <iostream>
#include <QDebug>
#include "loggingcategories.h"

TestCoordinatescontainer::TestCoordinatescontainer(QObject *parent) :
    QObject(parent)
{
}


void TestCoordinatescontainer::testCoordinatsInsertion()
{

    Coordinates c1(1, 1);
    Coordinates c2(2, 2);
    Coordinates c3(3, 3);
    Coordinates c4(4, 4);

    CoordiantesContainer::Instance().setCoordinates(1, c1);
    QCOMPARE(CoordiantesContainer::Instance().length(), 1);

    CoordiantesContainer::Instance().setCoordinates(2, c2);
    QCOMPARE(CoordiantesContainer::Instance().length(), 2);

    CoordiantesContainer::Instance().setCoordinates(3, c3);
    QCOMPARE(CoordiantesContainer::Instance().length(), 3);

    CoordiantesContainer::Instance().setCoordinates(4, c4);
    QCOMPARE(CoordiantesContainer::Instance().length(), 4);
}


void TestCoordinatescontainer::testPreparation()
{
    CoordiantesContainer::Instance().erase();
    QCOMPARE(CoordiantesContainer::Instance().length(), 0);
}

void TestCoordinatescontainer::testCoordinatsGetting()
{


    Coordinates c1(100, 100);
    Coordinates c2(150, 200);
    Coordinates c3(300, 350);
    Coordinates c4(400, 200);

    CoordiantesContainer::Instance().setCoordinates(1, c1);
    Coordinates c = CoordiantesContainer::Instance().getCoordinates(1);
    QCOMPARE(c.getX(), 100);

    CoordiantesContainer::Instance().setCoordinates(2, c2);
    c = CoordiantesContainer::Instance().getCoordinates(2);
    QCOMPARE(c.getX(), 150);

    CoordiantesContainer::Instance().setCoordinates(3, c3);
    c = CoordiantesContainer::Instance().getCoordinates(3);
    QCOMPARE(c.getX(), 300);

    CoordiantesContainer::Instance().setCoordinates(4, c4);
    c = CoordiantesContainer::Instance().getCoordinates(4);
    QCOMPARE(c.getX(), 400);

    CoordiantesContainer::Instance().setCoordinates(1, c1);
    c = CoordiantesContainer::Instance().getCoordinates(1);
    QCOMPARE(c.getY(), 100);

    CoordiantesContainer::Instance().setCoordinates(2, c2);
    c = CoordiantesContainer::Instance().getCoordinates(2);
    QCOMPARE(c.getY(), 200);

    CoordiantesContainer::Instance().setCoordinates(3, c3);
    c = CoordiantesContainer::Instance().getCoordinates(3);
    QCOMPARE(c.getY(), 350);

    CoordiantesContainer::Instance().setCoordinates(4, c4);
    c = CoordiantesContainer::Instance().getCoordinates(4);
    QCOMPARE(c.getY(), 200);

    QCOMPARE(CoordiantesContainer::Instance().length(), 4);
}

void TestCoordinatescontainer::testPreparation1()
{
    CoordiantesContainer::Instance().erase();
    QCOMPARE(CoordiantesContainer::Instance().length(), 0);
}

void TestCoordinatescontainer::testRemoveItem()
{
    Coordinates c1(100, 100);
    Coordinates c2(150, 200);
    Coordinates c3(300, 350);
    Coordinates c4(400, 200);


    CoordiantesContainer::Instance().setCoordinates(1, c1);
    CoordiantesContainer::Instance().setCoordinates(2, c2);
    CoordiantesContainer::Instance().setCoordinates(3, c3);
    CoordiantesContainer::Instance().setCoordinates(4, c4);

    QCOMPARE(CoordiantesContainer::Instance().length(), 4);
    Coordinates c(105, 100);
    CoordiantesContainer::Instance().removeItem(c);
    QCOMPARE(CoordiantesContainer::Instance().length(), 3);
}

void TestCoordinatescontainer::testRemoveItem_data()
{

}

void TestCoordinatescontainer::testPreparation2()
{
    CoordiantesContainer::Instance().erase();
    QCOMPARE(CoordiantesContainer::Instance().length(), 0);
}

void TestCoordinatescontainer::testFindBallByCoordinates()
{
    Coordinates c1(100, 100);
    Coordinates c2(150, 200);
    Coordinates c3(300, 350);
    Coordinates c4(400, 200);


    CoordiantesContainer::Instance().setCoordinates(1, c1);
    CoordiantesContainer::Instance().setCoordinates(2, c2);
    CoordiantesContainer::Instance().setCoordinates(3, c3);
    CoordiantesContainer::Instance().setCoordinates(4, c4);

    QCOMPARE(CoordiantesContainer::Instance().length(), 4);

    Coordinates r1(105, 100);
    QCOMPARE( CoordiantesContainer::Instance().findIdByCoordinates(r1), 1);


    Coordinates r2(300, 350);
    QCOMPARE( CoordiantesContainer::Instance().findIdByCoordinates(r2), 3);

    Coordinates r3(480, 380);
    QCOMPARE( CoordiantesContainer::Instance().findIdByCoordinates(r3), -1);

}

void TestCoordinatescontainer::testFindBallByCoordinates_data()
{

}


void TestCoordinatescontainer::testPreparation3()
{
    CoordiantesContainer::Instance().erase();
    QCOMPARE(CoordiantesContainer::Instance().length(), 0);
}

void TestCoordinatescontainer::testUpdateData()
{
    Coordinates c1(100, 100);
    Coordinates c2(150, 200);
    Coordinates c3(300, 350);
    Coordinates c4(400, 200);

    CoordiantesContainer::Instance().setCoordinates(1, c1);
    CoordiantesContainer::Instance().setCoordinates(2, c2);
    CoordiantesContainer::Instance().setCoordinates(3, c3);
    CoordiantesContainer::Instance().setCoordinates(4, c4);

    QCOMPARE(CoordiantesContainer::Instance().length(), 4);

    Coordinates c5(105, 100);
    CoordiantesContainer::Instance().updateItem(2, c5);
    Coordinates r1 = CoordiantesContainer::Instance().getCoordinates(2);
    QCOMPARE( r1.getX(), 105);
}
