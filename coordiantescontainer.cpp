#include "coordinatescontainer.h"
#include "collisions.h"
#include <QDebug>
#include "loggingcategories.h"

CoordinatesContainer::CoordinatesContainer()
{
}

void CoordinatesContainer::setCoordinates(int id, Coordinates &coordinates)
{
    while(!mutex.try_lock());
    allCoordinates.insert(std::make_pair(id, coordinates));
    mutex.unlock();
}

Coordinates& CoordinatesContainer::getCoordinates(int id)
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

int CoordinatesContainer::length()
{
    return allCoordinates.size();
}

void CoordinatesContainer::removeItem(Coordinates &coordiantes)
{
    int id = findIdByCoordinates(coordiantes);

    while(!mutex.try_lock());
    if( id > -1)
        allCoordinates.erase(id);
    mutex.unlock();
}

void CoordinatesContainer::removeItem(int id)
{
    while(!mutex.try_lock());
    allCoordinates.erase(id);
    mutex.unlock();
}

void CoordinatesContainer::updateItem(int id, Coordinates &coordinates)
{
    while(!mutex.try_lock());
    std::map<int, Coordinates>::iterator it;
    it = allCoordinates.find(id);
    if(it != allCoordinates.end())
        it->second = coordinates;
    mutex.unlock();
}

int CoordinatesContainer::findIdByCoordinates(Coordinates &coordinates)
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

void CoordinatesContainer::erase()
{
    while(!mutex.try_lock());
    allCoordinates.clear();
    mutex.unlock();
}

std::map<int, Coordinates> CoordinatesContainer::getContainer()
{
    return allCoordinates;
}

void CoordinatesContainer::setContainer(std::map<int, Coordinates> &container)
{
    while(!mutex.try_lock());
    allCoordinates = container;
    mutex.unlock();
}
