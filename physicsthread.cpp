#include "physicsthread.h"
#include "coordinatescontainer.h"
#include "coordinates.h"
#include <QDebug>
#include <thread>

#include "loggingcategories.h"
#include "coordinatescontainer.h"
#include "coordinates.h"

PhysicsThread::PhysicsThread()
{

}

PhysicsThread::~PhysicsThread()
{

}

double PhysicsThread::getForce(int a)
{
    if(a == 0) return 0;

    return (1/(double)a) - (1 / ((double)a * (double)a));
}

void PhysicsThread::physicsCalculation()
{
    std::map<int, Coordinates> s = CoordinatesContainer::Instance().getContainer();

    std::map<int, Coordinates>::iterator it;
    for(it = s.begin(); it != s.end(); ++it)
    {
        std::vector<int> buf;
        std::map<int, Coordinates>::iterator it1;
        for(it1 = s.begin(); it1 != s.end(); ++it1)
        {
            int l = Coordinates::lengthBetweenTwoPoints(it->second, it1->second);
            if(l == 0) continue;

            double f = getForce(l);

            Coordinates c1 = it->second;
            Coordinates c2 = it1->second;

            c1.m_dX = (f * (c2.getX() - c1.getX())/l) * 100;
            c1.m_dY = (f * (c2.getY() - c1.getY())/l) * 100;

            c1.m_x += c1.m_dX;
            c1.m_y += c1.m_dY;

            it->second = c1;
            CoordinatesContainer::Instance().updateItem(it->first, c1);
        }
    }
}

void PhysicsThread::operator ()()
{
    qInfo(logInfo()) << "Input to the thread" << endl;
    while(true)
    {
        physicsCalculation();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

}
