#include "collisions.h"
#include <map>

Collisions::Collisions()
{
}

bool Collisions::isAvaiblePos(CoordiantesContainer *cont, Coordinates *c)
{
    return isPlaceCompareOtherBalls(cont, c) && isPlaceCompareWalls(c);
}

bool Collisions::isPlaceCompareOtherBalls( CoordiantesContainer *cont, Coordinates *c)
{

    std::map<int, Coordinates*> container = cont->getContainer();

    std::map<int, Coordinates*>::iterator it;
    for(it = container.begin(); it != container.end(); ++it)
    {
        if(!hasEnoughPlaceBetweenTwoBalls(it->second, c))
          return false;
    }

    return true;
}

bool Collisions::isPlaceCompareWalls(Coordinates *c)
{
    int rangeToX0Wall = Coordinates::lengthBetweenTwoPoints(c, new Coordinates(0, c->getY()));
    int rangeToY0Wall = Coordinates::lengthBetweenTwoPoints(c, new Coordinates(c->getX(), 0));
    int rangeToXMaxWall = Coordinates::lengthBetweenTwoPoints(c, new Coordinates(500, c->getY()));
    int rangeToYMaxWall = Coordinates::lengthBetweenTwoPoints(c, new Coordinates(c->getX(), 500));

    return rangeToX0Wall >= 25 && rangeToY0Wall >= 25 && rangeToXMaxWall >= 25 && rangeToYMaxWall >= 25;
}

bool Collisions::isCoordinateLayInTheBall(Coordinates *c, Coordinates *b)
{
    return !isLengthBetweenTwoBallsMoreThenLength(c, b, 25);
}

bool Collisions::hasEnoughPlaceBetweenTwoBalls(Coordinates *c1, Coordinates *c2)
{
    return isLengthBetweenTwoBallsMoreThenLength(c1, c2, 50);
}

bool Collisions::isLengthBetweenTwoBallsMoreThenLength(Coordinates *c1, Coordinates *c2, int length)
{
    return Coordinates::lengthBetweenTwoPoints(c1, c2) >= length;
}
