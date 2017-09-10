#include "collisions.h"
#include <map>

Collisions::Collisions()
{
}

bool Collisions::isAvaiblePos(Coordinates &c)
{
    return isPlaceCompareOtherBalls(c) && isPlaceCompareWalls(c);
}

bool Collisions::isPlaceCompareOtherBalls(Coordinates &c)
{

    std::map<int, Coordinates> container = CoordiantesContainer::Instance().getContainer();

    std::map<int, Coordinates>::iterator it;
    for(it = container.begin(); it != container.end(); ++it)
    {
        if(!hasEnoughPlaceBetweenTwoBalls(it->second, c))
          return false;
    }

    return true;
}

bool Collisions::isPlaceCompareWalls(Coordinates& c)
{
    Coordinates pointToWall1(0, c.getY());
    int rangeToX0Wall = Coordinates::lengthBetweenTwoPoints(c, pointToWall1);

    Coordinates pointToWall2(c.getX(), 0);
    int rangeToY0Wall = Coordinates::lengthBetweenTwoPoints(c, pointToWall2);

    Coordinates pointToWall3(500, c.getY());
    int rangeToXMaxWall = Coordinates::lengthBetweenTwoPoints(c, pointToWall3);

    Coordinates pointToWall4(c.getX(), 500);
    int rangeToYMaxWall = Coordinates::lengthBetweenTwoPoints(c, pointToWall4);

    return rangeToX0Wall >= 50 || rangeToY0Wall >= 50 || rangeToXMaxWall >= 50 || rangeToYMaxWall >= 50;
}

bool Collisions::isCoordinateLayInTheBall(Coordinates &c, Coordinates &b)
{
    return !isLengthBetweenTwoBallsMoreThenLength(c, b, 25);
}

bool Collisions::hasEnoughPlaceBetweenTwoBalls(Coordinates &c1, Coordinates &c2)
{
    return isLengthBetweenTwoBallsMoreThenLength(c1, c2, 50);
}

bool Collisions::isLengthBetweenTwoBallsMoreThenLength(Coordinates &c1, Coordinates &c2, int length)
{
    return Coordinates::lengthBetweenTwoPoints(c1, c2) >= length;
}

bool Collisions::isBorder(Coordinates &c)
{
    return (c.getX() + 25) > 0 && (c.getX() + 25) < 500 &&
            (c.getY() + 25) >0 && (c.getY() + 25) < 500;
}
