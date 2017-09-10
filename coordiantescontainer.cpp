#include "coordiantescontainer.h"
#include "collisions.h"
#include <QDebug>
#include "loggingcategories.h"

CoordiantesContainer::CoordiantesContainer()
{
}

void CoordiantesContainer::setCoordinates(int id, Coordinates &coordinates)
{
    while(!mutex.try_lock());
    allCoordinates.insert(std::make_pair(id, coordinates));
    mutex.unlock();
}

Coordinates& CoordiantesContainer::getCoordinates(int id)
{
    while(!mutex.try_lock());
    std::map<int, Coordinates>::iterator it;
    for(it = allCoordinates.begin(); it != allCoordinates.end(); ++it)
    {
        if(it->first == id) break;
    }
    mutex.unlock();
    return it->second;
}

int CoordiantesContainer::length()
{
    return allCoordinates.size();
}

void CoordiantesContainer::removeItem(Coordinates &coordiantes)
{
    int id = findIdByCoordinates(coordiantes);

    while(!mutex.try_lock());
    if( id > -1)
        allCoordinates.erase(id);
    mutex.unlock();
}

void CoordiantesContainer::removeItem(int id)
{
    while(!mutex.try_lock());
    allCoordinates.erase(id);
    mutex.unlock();
}

void CoordiantesContainer::updateItem(int id, Coordinates &coordinates)
{
    while(!mutex.try_lock());
    std::map<int, Coordinates>::iterator it;
    it = allCoordinates.find(id);
    if(it != allCoordinates.end())
        it->second = coordinates;
    mutex.unlock();
}

int CoordiantesContainer::findIdByCoordinates(Coordinates &coordinates)
{

    while(!mutex.try_lock());
    int id = -1;
    std::map<int, Coordinates>::iterator it;
    for(it = allCoordinates.begin(); it != allCoordinates.end(); ++it)
    {
      //  qInfo(logInfo()) << "Id " << it->first << endl;
        if(Collisions::isCoordinateLayInTheBall(it->second, coordinates))
        {
            id = it->first;
            break;
        }
    }
    mutex.unlock();
    return id;
}

void CoordiantesContainer::erase()
{
    while(!mutex.try_lock());
    allCoordinates.clear();
    mutex.unlock();
}

std::map<int, Coordinates> CoordiantesContainer::getContainer()
{
    return allCoordinates;
}

void CoordiantesContainer::setContainer(std::map<int, Coordinates> &container)
{
    while(!mutex.try_lock());
    allCoordinates = container;
    mutex.unlock();
}
