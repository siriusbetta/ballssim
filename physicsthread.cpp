#include "physicsthread.h"
#include "coordinatescontainer.h"
#include "coordinates.h"
#include <thread>

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
    std::map<int, Coordinates> coordinats = CoordinatesContainer::Instance().getContainer();

    std::map<int, Coordinates>::iterator it;
    for(it = coordinats.begin(); it != coordinats.end(); ++it)
    {
        Coordinates coordinate1 = it->second;
        std::map<int, Coordinates>::iterator it1;
        for(it1 = coordinats.begin(); it1 != coordinats.end(); ++it1)
        {
            int length = Coordinates::lengthBetweenTwoPoints(it->second, it1->second);

            if(length == 0) continue; /*< If length equal zero skips current iteration */

            double force = getForce(length);

            Coordinates coordinate2 = it1->second;

            coordinate1.m_dX = (force * (coordinate2.getX() - coordinate1.getX())/length) * 5; /*< Step to x */
            coordinate1.m_dY = (force * (coordinate2.getY() - coordinate1.getY())/length) * 5; /*< Step to y */

            coordinate1.m_x += coordinate1.m_dX;
            coordinate1.m_y += coordinate1.m_dY;

            it->second = coordinate1;
            CoordinatesContainer::Instance().updateItem(it->first, coordinate1);
        }
    }
}

void PhysicsThread::operator ()()
{
    while(true)
    {
        physicsCalculation();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
