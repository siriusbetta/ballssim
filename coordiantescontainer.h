/*!
 *	\brief ������ ����� �������� ���������� ��� ��������� ����� Coordinates
 *
 *	������ ��� ��� �������� ����� ������� id � ���� ��������� x � y, �������
 *	����������� � ���� �� id � ��������� �� ������ Coordinates
 *
 */
#ifndef COORDIANTESCONTAINER_H
#define COORDIANTESCONTAINER_H

#include <map>
#include "coordinates.h"

class CoordiantesContainer
{
public:

    CoordiantesContainer();

    ~CoordiantesContainer();

    /*!
     * \brief ��������� ���������� ���� � �������� �� id ����

     * \param id
     * \param coordinates
     */
    void setCoordinates(int id, Coordinates *coordinates);

    /*!
     * \brief ���������� ���������� ���� �� ��������� �� id ����
     *
     * \return Coordinates ���������� ��������� �� ���������� �������� ����, ���� ��� �� ������ ��������� �������
     */
    Coordinates * getCoordinates(int id);

    /*!
     * \brief Returns number of maps
     *
     * \return int
     */
    int length();

    /*!
     * \brief ��������� ������������ ������������ ������ ���� ������������ ���� � ������ �����
     *
     * \param c ���������� �������� �������
     * \return bool
     */
    bool isAvaiblePos(Coordinates *c);

    /*!
     * \brief Remove balls if current coordinats can be match in map
     *
     * \param coordiantes
     */
    void removeItem(Coordinates *coordiantes);

    /*!
     * \brief ��������� ������������ ������������ ����������� ������ ����� �� ���� ��������� �������� ����
     *
     * ����� ������� ����� ��� ������� ���� � ����������
     *
     * \param c ���������� �������� �������
     * \return bool
     */
    bool isPlaceCompareOtherBalls(Coordinates *c);

    /*!
     * \brief Looking for a ball id by given coordinates
     *
     * \param coordiantes
     */
    int findBallByCoordinates(Coordinates *coordinates);

    /*!
     * \brief ����� ���������� ������ ���������� ������������ ������ ���� ���������
     *
     * ���� �� ����� ������ 25 ��� ������ 575 �� ����� ����������� �� ����� ���������� false
     *
     * \param c ���������� �������� �������
     * \return bool
     */
    bool isPlaceCompareWalls(Coordinates *c);

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
    bool hasEnoughPlaceBetweenTwoBalls(Coordinates *c1, Coordinates *c2);

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
    bool isCoordinateLayInTheBall(Coordinates *c, Coordinates *b);

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
    bool isLengthBetweenTwoBallsMoreThenLength(Coordinates *c1, Coordinates *c2, int length);


    std::map<int, Coordinates*> allCoordinates; //! �������� ����
};


#endif // COORDIANTESCONTAINER_H
