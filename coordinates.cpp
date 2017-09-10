#include <cmath>
#include "coordinates.h"

Coordinates::Coordinates(int x, int y , double d_x, double d_y ) : m_x(x), m_y(y), m_dX(d_x), m_dY(d_y)
{
}

Coordinates::~Coordinates()
{

}

Coordinates::Coordinates(const Coordinates &c) : m_x(c.m_x), m_y(c.m_y)
{

}

const Coordinates& Coordinates::operator = ( const Coordinates &c)
{
    m_x = c.m_x;
    m_y = c.m_y;
    m_dX = c.m_dX;
    m_dY = c.m_dY;
    return *this;
}

double Coordinates::getX()
{
    return m_x;
}

double Coordinates::getY()
{
    return m_y;
}

double Coordinates::lengthBetweenTwoPoints(Coordinates &c1, Coordinates &c2)
{
    return sqrt( (c2.getX() - c1.getX()) * (c2.getX() - c1.getX()) +
                 (c2.getY() - c1.getY()) * (c2.getY() - c1.getY()));
}
