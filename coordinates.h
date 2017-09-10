#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates
{
public:

    Coordinates( int x, int y, double m_dX = 0, double m_dY = 0);

    ~Coordinates();

    Coordinates(const Coordinates & c);

    const Coordinates& operator = (const Coordinates& c);

    static double lengthBetweenTwoPoints(Coordinates &c1, Coordinates &c2);

    double getX();
    double getY();


    int m_x;
    int m_y;

    double m_dX;
    double m_dY;
};

#endif // COORDINATES_H
