#ifndef TESTCOORDINATESCONTAINER_H
#define TESTCOORDINATESCONTAINER_H

#include <QObject>
#include <QTest>
#include "../coordinatescontainer.h"

class TestCoordinatescontainer : public QObject
{
    Q_OBJECT
public:
    explicit TestCoordinatescontainer(QObject *parent = 0);
    
signals:
    
private slots:


    void testCoordinatsInsertion();
    void testPreparation();
    void testCoordinatsGetting();

    void testPreparation1();

    void testFindBallByCoordinates();
    void testFindBallByCoordinates_data();

    void testPreparation2();
    void testRemoveItem();
    void testRemoveItem_data();
    void testPreparation3();

    void testUpdateData();

};

#endif // TESTCOORDINATESCONTAINER_H
