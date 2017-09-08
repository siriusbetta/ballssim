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
     * \brief Remove balls if current coordinats can be match in map
     *
     * \param coordiantes
     */
    void removeItem(Coordinates *coordiantes);

    /*!
     * \brief Looking for a ball id by given coordinates
     *
     * \param coordiantes
     */
    int findIdByCoordinates(Coordinates *coordinates);

    std::map<int, Coordinates*> getContainer();

    std::map<int, Coordinates*> allCoordinates; //! �������� ����
};


#endif // COORDIANTESCONTAINER_H
