#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates
{
public:
    Coordinates( int x, int y);

    ~Coordinates();

    Coordinates(const Coordinates & c);

    const Coordinates& operator = (const Coordinates& c);

    int getX();
    int getY();


    int m_x;
    int m_y;
};

#endif // COORDINATES_H
