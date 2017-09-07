#ifndef TESTCOORDINATES_H
#define TESTCOORDINATES_H

#include <QObject>
#include <QTest>
#include "../coordinates.h"

class TestCoordinates : public QObject
{
    Q_OBJECT
public:
    explicit TestCoordinates(QObject *parent = 0);
    
signals:
    
private slots:
    void test_x();
    void test_y();
    void test_length_calculations();
};
#endif // TESTCOOvoid test_length_calculations();RDINATES_H
