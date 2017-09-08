#include <cmath>
#include "coordinates.h"

Coordinates::Coordinates(int x, int y) : m_x(x), m_y(y)
{
}

Coordinates::~Coordinates()
{

}

Coordinates::Coordinates(const Coordinates &c) : m_x(c.m_x), m_y(c.m_y)
{

}

/*
const Coordinates& Coordinates::operator = ( const Coordinates &c)
{
    m_x = c.m_x;
    m_y = c.m_y;
    return *this;
}
*/


/*
bool Coordinates::operator == (Coordinates& c) const
{
    return m_x == c.m_x && m_y == c.m_y;
}
*/
int Coordinates::getX()
{
    return m_x;
}

int Coordinates::getY()
{
    return m_y;
}

int Coordinates::lengthBetweenTwoPoints(Coordinates *c1, Coordinates *c2)
{
    return (int)sqrt( (c2->getX() - c1->getX()) * (c2->getX() - c1->getX()) +
                 (c2->getY() - c1->getY()) * (c2->getY() - c1->getY()));
}
