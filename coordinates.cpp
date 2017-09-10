#include <cmath>
#include "coordinates.h"

Coordinates::Coordinates(double x, double y /*, double d_x, double d_y */) : m_x(x), m_y(y)//, dX(d_x), dY(d_y)
{
    dX = 1;
    dY = 1;
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
    dX = c.dX;
    dY = c.dY;
    return *this;
}



/*
bool Coordinates::operator == (Coordinates& c) const
{
    return m_x == c.m_x && m_y == c.m_y;
}
*/
double Coordinates::getX()
{
    return m_x;
}

double Coordinates::getY()
{
    return m_y;
}

int Coordinates::lengthBetweenTwoPoints(Coordinates &c1, Coordinates &c2)
{
    return (int)sqrt( (c2.getX() - c1.getX()) * (c2.getX() - c1.getX()) +
                 (c2.getY() - c1.getY()) * (c2.getY() - c1.getY()));
}
