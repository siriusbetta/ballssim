#include <QCoreApplication>
#include <QTest>
#include <iostream>
#include "testcoordinates.h"
#include "testcoordinatescontainer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTest::qExec(new TestCoordinatescontainer(), argc, argv);
    //QTest::qExec(new TestCoordinates(), argc, argv);

    return a.exec();
}
