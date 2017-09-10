#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "coordinatescontainer.h"
#include "coordinates.h"

class Collisions
{
public:
    Collisions();

/*!
     * \brief ��������� ������������ ������������ ������ ���� ������������ ���� � ������ �����
     *
     * \param c ���������� �������� �������
     * \return bool
     */
    static bool isAvaiblePos(Coordinates &c);

    /*!
     * \brief ��������� ������������ ������������ ����������� ������ ����� �� ���� ��������� �������� ����
     *
     * ����� ������� ����� ��� ������� ���� � ����������
     *
     * \param c ���������� �������� �������
     * \return bool
     */
   static bool isPlaceCompareOtherBalls(Coordinates &c);
/*!
     * \brief ����� ���������� ���������� ������� ���� �����
     *
     *	���� ����� ���� � ����� ����� ������ 50, �� �����
     * ���������� false.
     *
     * \param c1 ���������� ������� �������
     * \param c2 ���������� ������� �������
     *
     *	\return bool
     */
    static bool hasEnoughPlaceBetweenTwoBalls(Coordinates &c1, Coordinates &c2);

    /*!
     * \brief ����� ���������� ������ ���������� ������������ ������ ���� ���������
     *
     * ���� �� ����� ������ 25 ��� ������ 575 �� ����� ����������� �� ����� ���������� false
     *
     * \param c ���������� �������� �������
     * \return bool
     */
    static bool isPlaceCompareWalls(Coordinates &c);

     /*!
     * \breaf Checks lentgth between two coordinates
     *
     *	if length less or equal 25 means that given coordinate lays into the ball
     *
     * \param c1
     * \param c2
     *
     * \return bool true lenght less or equal 25 (radius ball)
     */
    static bool isCoordinateLayInTheBall(Coordinates &c, Coordinates &b);

    /*!
     * \breaf Compare lentgth between two balls and different length value
     *
     *
     * \param c1
     * \param c2
     * \param length
     *
     * \return bool true is lenght between balls more or equal given length
     */
    static bool isLengthBetweenTwoBallsMoreThenLength(Coordinates &c1, Coordinates &c2, int length);

    static bool isBorder(Coordinates &c);

    static int width;
    static int height;
};

#endif // COLLISIONS_H
