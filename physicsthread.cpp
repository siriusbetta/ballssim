#include "physicsthread.h"
#include "coordiantescontainer.h"
#include "coordinates.h"
#include <QDebug>
#include <thread>

#include "loggingcategories.h"
#include "coordiantescontainer.h"
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
    std::map<int, Coordinates> s = CoordiantesContainer::Instance().getContainer();

    std::map<int, Coordinates>::iterator it;
    for(it = s.begin(); it != s.end(); ++it)
    {
        std::vector<int> buf;
        std::map<int, Coordinates>::iterator it1;
        for(it1 = s.begin(); it1 != s.end(); ++it1)
        {
            int l = Coordinates::lengthBetweenTwoPoints(it->second, it1->second);
            double f = getForce(l);

            Coordinates c1 = it->second;
            Coordinates c2 = it1->second;
            //std::cout << "x - " << c1.m_x << std::endl;
            if(l == 0) continue;

            c1.dX = (f * ((double)c2.getX() - (double)c1.getX())/l) * 5;
            c1.dY = (f * (c2.getY() - c1.getY())/l) * 5;


            //std::cout << "x - " << c1.m_x << std::endl;
            //std::cout << "y - " << c1.m_y << std::endl;

            c2.dX = (f * (c1.getX() - c2.getX())/l) * 5;
            c2.dY = (f * (c1.getY() - c2.getY())/l) * 5;

            c1.m_x += c1.dX;
            c1.m_y += c1.dY;
            c2.m_x += c2.dX;
            c2.m_y += c2.dY;

            it->second = c1;
            it1->second = c2;
            CoordiantesContainer::Instance().updateItem(it->first, c1);
            CoordiantesContainer::Instance().updateItem(it1->first, c2);
        }
    }
}

void PhysicsThread::operator ()()
{
    qInfo(logInfo()) << "Input to the thread" << endl;
    while(true)
    {
        physicsCalculation();
        /*
        std::map<int, Coordinates>m = CoordiantesContainer::Instance().getContainer();
        std::map<int, Coordinates>::iterator it;
        for(it = m.begin(); it != m.end(); ++it)
        {
            Coordinates c = it->second;
            c.m_y++;
            CoordiantesContainer::Instance().updateItem(it->first, c);
        }
        */

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

    }

}
