/*!
 *	\brief Данный класс является контенером для координат шаров Coordinates
 *
 *	Каждый шар при создании имеет атрибут id и пару координат x и y, которые
 *	сохраняются в мапе по id и указателю на обьект Coordinates
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
     * \brief Вставляет координату шара в контенер по id шара

     * \param id
     * \param coordinates
     */
    void setCoordinates(int id, Coordinates *coordinates);

    /*!
     * \brief Возвращает координату шара из контенера по id шара
     *
     * \return Coordinates возвращает указатель на координаты текущего шара, если нет то вернет последний элемент
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

    std::map<int, Coordinates*> allCoordinates; //! Контенер мапа
};


#endif // COORDIANTESCONTAINER_H
