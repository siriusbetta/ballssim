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

    CoordinatesContainer::Instance().setCoordinates(1, c1);
    QCOMPARE(CoordinatesContainer::Instance().length(), 1);

    CoordinatesContainer::Instance().setCoordinates(2, c2);
    QCOMPARE(CoordinatesContainer::Instance().length(), 2);

    CoordinatesContainer::Instance().setCoordinates(3, c3);
    QCOMPARE(CoordinatesContainer::Instance().length(), 3);

    CoordinatesContainer::Instance().setCoordinates(4, c4);
    QCOMPARE(CoordinatesContainer::Instance().length(), 4);
}


void TestCoordinatescontainer::testPreparation()
{
    CoordinatesContainer::Instance().erase();
    QCOMPARE(CoordinatesContainer::Instance().length(), 0);
}

void TestCoordinatescontainer::testCoordinatsGetting()
{


    Coordinates c1(100, 100);
    Coordinates c2(150, 200);
    Coordinates c3(300, 350);
    Coordinates c4(400, 200);

    CoordinatesContainer::Instance().setCoordinates(1, c1);
    Coordinates c = CoordinatesContainer::Instance().getCoordinates(1);
    QCOMPARE(c.getX(), 100.0);

    CoordinatesContainer::Instance().setCoordinates(2, c2);
    c = CoordinatesContainer::Instance().getCoordinates(2);
    QCOMPARE(c.getX(), 150.0);

    CoordinatesContainer::Instance().setCoordinates(3, c3);
    c = CoordinatesContainer::Instance().getCoordinates(3);
    QCOMPARE(c.getX(), 300.0);

    CoordinatesContainer::Instance().setCoordinates(4, c4);
    c = CoordinatesContainer::Instance().getCoordinates(4);
    QCOMPARE(c.getX(), 400.0);

    CoordinatesContainer::Instance().setCoordinates(1, c1);
    c = CoordinatesContainer::Instance().getCoordinates(1);
    QCOMPARE(c.getY(), 100.0);

    CoordinatesContainer::Instance().setCoordinates(2, c2);
    c = CoordinatesContainer::Instance().getCoordinates(2);
    QCOMPARE(c.getY(), 200.0);

    CoordinatesContainer::Instance().setCoordinates(3, c3);
    c = CoordinatesContainer::Instance().getCoordinates(3);
    QCOMPARE(c.getY(), 350.0);

    CoordinatesContainer::Instance().setCoordinates(4, c4);
    c = CoordinatesContainer::Instance().getCoordinates(4);
    QCOMPARE(c.getY(), 200.0);

    QCOMPARE(CoordinatesContainer::Instance().length(), 4);
}

void TestCoordinatescontainer::testPreparation1()
{
    CoordinatesContainer::Instance().erase();
    QCOMPARE(CoordinatesContainer::Instance().length(), 0);
}

void TestCoordinatescontainer::testRemoveItem()
{
    Coordinates c1(100, 100);
    Coordinates c2(150, 200);
    Coordinates c3(300, 350);
    Coordinates c4(400, 200);


    CoordinatesContainer::Instance().setCoordinates(1, c1);
    CoordinatesContainer::Instance().setCoordinates(2, c2);
    CoordinatesContainer::Instance().setCoordinates(3, c3);
    CoordinatesContainer::Instance().setCoordinates(4, c4);

    QCOMPARE(CoordinatesContainer::Instance().length(), 4);
    Coordinates c(105, 100);
    CoordinatesContainer::Instance().removeItem(c);
    QCOMPARE(CoordinatesContainer::Instance().length(), 3);
}

void TestCoordinatescontainer::testRemoveItem_data()
{

}

void TestCoordinatescontainer::testPreparation2()
{
    CoordinatesContainer::Instance().erase();
    QCOMPARE(CoordinatesContainer::Instance().length(), 0);
}

void TestCoordinatescontainer::testFindBallByCoordinates()
{
    Coordinates c1(100, 100);
    Coordinates c2(150, 200);
    Coordinates c3(300, 350);
    Coordinates c4(400, 200);


    CoordinatesContainer::Instance().setCoordinates(1, c1);
    CoordinatesContainer::Instance().setCoordinates(2, c2);
    CoordinatesContainer::Instance().setCoordinates(3, c3);
    CoordinatesContainer::Instance().setCoordinates(4, c4);

    QCOMPARE(CoordinatesContainer::Instance().length(), 4);

    Coordinates r1(105, 100);
    QCOMPARE( CoordinatesContainer::Instance().findIdByCoordinates(r1), 1);


    Coordinates r2(300, 350);
    QCOMPARE( CoordinatesContainer::Instance().findIdByCoordinates(r2), 3);

    Coordinates r3(480, 380);
    QCOMPARE( CoordinatesContainer::Instance().findIdByCoordinates(r3), -1);

}

void TestCoordinatescontainer::testFindBallByCoordinates_data()
{

}


void TestCoordinatescontainer::testPreparation3()
{
    CoordinatesContainer::Instance().erase();
    QCOMPARE(CoordinatesContainer::Instance().length(), 0);
}

void TestCoordinatescontainer::testUpdateData()
{
    Coordinates c1(100, 100);
    Coordinates c2(150, 200);
    Coordinates c3(300, 350);
    Coordinates c4(400, 200);

    CoordinatesContainer::Instance().setCoordinates(1, c1);
    CoordinatesContainer::Instance().setCoordinates(2, c2);
    CoordinatesContainer::Instance().setCoordinates(3, c3);
    CoordinatesContainer::Instance().setCoordinates(4, c4);

    QCOMPARE(CoordinatesContainer::Instance().length(), 4);

    Coordinates c5(105, 100);
    CoordinatesContainer::Instance().updateItem(2, c5);
    Coordinates r1 = CoordinatesContainer::Instance().getCoordinates(2);
    QCOMPARE( r1.getX(), 105.0);
}
