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
#include <algorithm>
#include <mutex>
#include "coordinates.h"

class CoordiantesContainer
{
public:
    static CoordiantesContainer& Instance()
    {
        static CoordiantesContainer c;
        return c;
    }


    /*!
     * \brief ��������� ���������� ���� � �������� �� id ����

     * \param id
     * \param coordinates
     */
    void setCoordinates(int id, Coordinates &coordinates);

    /*!
     * \brief ���������� ���������� ���� �� ��������� �� id ����
     *
     * \return Coordinates ���������� ��������� �� ���������� �������� ����, ���� ��� �� ������ ��������� �������
     */
    Coordinates & getCoordinates(int id);

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
    void removeItem(Coordinates &coordiantes);

    /*!
     * \brief Remove balls by id
     *
     * \param coordiantes
     */
    void removeItem(int id);

    void updateItem(int id, Coordinates &coordinates);

    /*!
     * \brief Looking for a ball id by given coordinates
     *
     * \param coordiantes
     */
    int findIdByCoordinates(Coordinates& coordinates);

    void erase();

    std::map<int, Coordinates> getContainer();

    void setContainer(std::map<int, Coordinates>& container);

    std::mutex mutex;

private:
    CoordiantesContainer();

    std::map<int, Coordinates> allCoordinates; //! �������� ����
};


#endif // COORDIANTESCONTAINER_H
