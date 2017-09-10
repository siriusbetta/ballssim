#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates
{
public:
    //Coordinates( int x, int y);

    Coordinates( double x, double y);//, double dX = 0, double dY = 0);

    ~Coordinates();

    Coordinates(const Coordinates & c);

    const Coordinates& operator = (const Coordinates& c);
   // bool operator == (Coordinates& c) const;

    static int lengthBetweenTwoPoints(Coordinates &c1, Coordinates &c2);

    double getX();
    double getY();


    double m_x;
    double m_y;

    double dX;
    double dY;
};

#endif // COORDINATES_H
