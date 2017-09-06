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
#include <coordinates.h>

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
     * \brief ��������� ������������ ������������ ������ ���� ������������ ���� � ������ �����
     *
     * \param c ���������� �������� �������
     * \return bool
     */
    bool isAvaiblePos(Coordinates *c);

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
    bool compareTwoCoordiantes(Coordinates *c1, Coordinates *c2);

    std::map<int, Coordinates*> allCoordinates; //! �������� ����
};

#endif // COORDIANTESCONTAINER_H
