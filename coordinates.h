#ifndef COORDINATES_H
#define COORDINATES_H

/*!
 * Class implements Coordinates object
 */
class Coordinates
{
public:

  /*!
   * Coordinates c-r
   * @param x
   * @param y
   * @param m_dX  moving step to x direction
   * @param m_dY  moving step to y
   */
    Coordinates( int x, int y, double m_dX = 0, double m_dY = 0);

    /*!
     * Coordinates dest-r
     */
    ~Coordinates();

    /*!
     * [Coordinates copy c-r
     * @param c Coordinates object
     */
    Coordinates(const Coordinates & c);

    /*!
     * Defines operator
     * @param  c Coordinates object
     * @return   Coordinates object
     */
    const Coordinates& operator = (const Coordinates& c);

    /*!
     * static method, calculates length between two points
     * @param  c1 First coordinates
     * @param  c2 Second coordinates
     * @return  double length  
     */
    static double lengthBetweenTwoPoints(Coordinates &c1, Coordinates &c2);

    double getX();
    double getY();


    int m_x;
    int m_y;

    double m_dX;
    double m_dY;
};

#endif // COORDINATES_H
