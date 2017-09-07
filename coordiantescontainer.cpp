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

int CoordiantesContainer::length()
{
    return allCoordinates.size();
}

bool CoordiantesContainer::isAvaiblePos(Coordinates *c)
{
    return isPlaceCompareOtherBalls(c);// || isPlaceCompareWalls(c);
}

bool CoordiantesContainer::isPlaceCompareOtherBalls(Coordinates *c)
{
    std::map<int, Coordinates*>::iterator it;
    for(it = allCoordinates.begin(); it != allCoordinates.end(); ++it)
    {
        if(!compareTwoCoordiantes(it->second, c))
          return false;
    }

    return true;
}

bool CoordiantesContainer::isPlaceCompareWalls(Coordinates *c)
{
    int rangeToX0Wall = Coordinates::lengthBetweenTwoPoints(c, new Coordinates(0, c->getY()));
    int rangeToY0Wall = Coordinates::lengthBetweenTwoPoints(c, new Coordinates(c->getX(), 0));
    int rangeToXMaxWall = Coordinates::lengthBetweenTwoPoints(c, new Coordinates(500, c->getY()));
    int rangeToYMaxWall = Coordinates::lengthBetweenTwoPoints(c, new Coordinates(c->getX(), 500));
    return rangeToX0Wall >= 25 && rangeToY0Wall >= 25 && rangeToXMaxWall >= 25 && rangeToYMaxWall >= 25;
}

bool CoordiantesContainer::compareTwoCoordiantes(Coordinates *c1, Coordinates *c2)
{
    return Coordinates::lengthBetweenTwoPoints(c1, c2) >= 50;
}
