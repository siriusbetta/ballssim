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

const Coordinates& Coordinates::operator = ( const Coordinates &c)
{
    m_x = c.m_x;
    m_y = c.m_y;
    return *this;
}

int Coordinates::getX()
{
    return m_x;
}

int Coordinates::getY()
{
    return m_y;
}
