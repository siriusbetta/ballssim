#ifndef TESTCOLLISIONS_H
#define TESTCOLLISIONS_H

#include <QObject>
#include <QTest>

class Testcollisions : public QObject
{
    Q_OBJECT
public:
    explicit Testcollisions( QObject *parent = 0) ;

signals:

private slots:
    void compareTwoCoordinates();
    void compareTwoCoordinates_data();

    void testChechLengthToTheWalls();

    void testChechLengthToTheWalls_data();
    void testIsPlaceCompareOtherBalls();
    void testIsPlaceCompareOtherBalls_data();
    void testIsAvaiblePos();
    void testIsAvaiblePos_data();
    void testIsCoordinateLayInTheBall();
    void testIsCoordinateLayInTheBall_data();
};

#endif // TESTCOLLISIONS_H
