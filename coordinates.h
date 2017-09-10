#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates
{
public:

    Coordinates( double x, double y);

    ~Coordinates();

    Coordinates(const Coordinates & c);

    const Coordinates& operator = (const Coordinates& c);

    static double lengthBetweenTwoPoints(Coordinates &c1, Coordinates &c2);

    double getX();
    double getY();


    double m_x;
    double m_y;

    double dX;
    double dY;
};

#endif // COORDINATES_H
