#ifndef TESTCOORDINATESCONTAINER_H
#define TESTCOORDINATESCONTAINER_H

#include <QObject>
#include <QTest>
#include "../coordiantescontainer.h"

class TestCoordinatescontainer : public QObject
{
    Q_OBJECT
public:
    explicit TestCoordinatescontainer(QObject *parent = 0);
    
signals:
    
private slots:
    void compareTwoCoordinates();
    void compareTwoCoordinates_data();

    void testChechLengthToTheWalls();
    void testChechLengthToTheWalls_data();

    void testCoordinatsInsertion();
    void testCoordinatsGetting();
    void testIsPlaceCompareOtherBalls();
    void testIsPlaceCompareOtherBalls_data();
    void testIsAvaiblePos();
    void testIsAvaiblePos_data();

    void testIsCoordinateLayInTheBall();
    void testIsCoordinateLayInTheBall_data();

    void testFindBallByCoordinates();
    void testFindBallByCoordinates_data();

    void testRemoveItem();
    void testRemoveItem_data();
};

#endif // TESTCOORDINATESCONTAINER_H
