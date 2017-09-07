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
};

#endif // TESTCOORDINATESCONTAINER_H
