#include "coordiantescontainer.h"
#include "collisions.h"

CoordiantesContainer::CoordiantesContainer()
{
}

CoordiantesContainer::~CoordiantesContainer()
{

}

void CoordiantesContainer::setCoordinates(int id, Coordinates *coordinates)
{
    allCoordinates.insert(std::make_pair(id, coordinates));
}

Coordinates* CoordiantesContainer::getCoordinates(int id)
{
    Coordinates *c = new Coordinates(0, 0);
    std::map<int, Coordinates*>::iterator it;
    for(it = allCoordinates.begin(); it != allCoordinates.end(); ++it)
    {
        if(it->first == id)
        {
            c = it->second;
            break;
        }
    }
    return c;
}

int CoordiantesContainer::length()
{
    return allCoordinates.size();
}

void CoordiantesContainer::removeItem(Coordinates *coordiantes)
{
    int id = findIdByCoordinates(coordiantes);
    if( id > -1)
        allCoordinates.erase(id);
}

int CoordiantesContainer::findIdByCoordinates(Coordinates *coordinates)
{
    int id = -1;
    std::map<int, Coordinates*>::iterator it;
    for(it = allCoordinates.begin(); it != allCoordinates.end(); ++it)
    {
        if(Collisions::isCoordinateLayInTheBall(it->second, coordinates))
        {
            id = it->first;
            break;
        }
    }
    return id;
}

std::map<int, Coordinates*> CoordiantesContainer::getContainer()
{
    return allCoordinates;
}
