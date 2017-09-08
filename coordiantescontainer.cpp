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
    int id = findBallByCoordinates(coordiantes);
    if( id > -1)
        allCoordinates.erase(id);
}

int CoordiantesContainer::findBallByCoordinates(Coordinates *coordinates)
{
    int id = -1;
    std::map<int, Coordinates*>::iterator it;
    for(it = allCoordinates.begin(); it != allCoordinates.end(); ++it)
    {
        if(isCoordinateLayInTheBall(it->second, coordinates))
        {
            id = it->first;
            break;
        }
    }
    return id;
}

bool CoordiantesContainer::isAvaiblePos(Coordinates *c)
{
    return isPlaceCompareOtherBalls(c) && isPlaceCompareWalls(c);
}

bool CoordiantesContainer::isPlaceCompareOtherBalls(Coordinates *c)
{
    std::map<int, Coordinates*>::iterator it;
    for(it = allCoordinates.begin(); it != allCoordinates.end(); ++it)
    {
        if(!hasEnoughPlaceBetweenTwoBalls(it->second, c))
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

bool CoordiantesContainer::isCoordinateLayInTheBall(Coordinates *c, Coordinates *b)
{
    return !isLengthBetweenTwoBallsMoreThenLength(c, b, 25);
}

bool CoordiantesContainer::hasEnoughPlaceBetweenTwoBalls(Coordinates *c1, Coordinates *c2)
{
    return isLengthBetweenTwoBallsMoreThenLength(c1, c2, 50);
}

bool CoordiantesContainer::isLengthBetweenTwoBallsMoreThenLength(Coordinates *c1, Coordinates *c2, int length)
{
    return Coordinates::lengthBetweenTwoPoints(c1, c2) >= length;
}
