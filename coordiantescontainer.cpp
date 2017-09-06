#include "coordiantescontainer.h"

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
    std::map<int, Coordinates*>::iterator it;
    for(it = allCoordinates.begin(); it != allCoordinates.end(); ++it)
    {
        if(it->first == id)
            break;
    }
    return it->second;
}

bool CoordiantesContainer::isAvaiblePos(Coordinates *c)
{
    return isPlaceCompareOtherBalls(c) || isPlaceCompareWalls(c);
}

bool CoordiantesContainer::isPlaceCompareOtherBalls(Coordinates *c)
{
    std::map<int, Coordinates*>::iterator it;
    for(it = allCoordinates.begin(); it != allCoordinates.end(); ++it)
    {
        if(compareTwoCoordiantes(it->second, c))
          return false;
    }

    return true;
}

bool CoordiantesContainer::isPlaceCompareWalls(Coordinates *c)
{
    return c->getX() < 25 || c->getX() > 575 || c->getY() < 25 || c->getY() > 575;
}

bool CoordiantesContainer::compareTwoCoordiantes(Coordinates *c1, Coordinates *c2)
{
    if(c1->getX() <= c2->getX() + 25 ||	c1->getY() <= c2->getY() + 25)
        return false;

    return true;
}
