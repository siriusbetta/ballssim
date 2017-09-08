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
     * \brief Проверяет допустимость расположение нового шара относительно стен и других шаров
     *
     * \param c Координата текущего объекта
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
     * \brief Проверяет допустимость расположения отностильно других шаров на поле симуляции текущего шара
     *
     * метод обходит через все элеметы мапы и сравнивает
     *
     * \param c Координата текущего объекта
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
     * \brief Метод сравнивает данную координату относительно границ поля симуляции
     *
     * если до стены муньше 25 или больше 575 по обоим координатам то метод возвращает false
     *
     * \param c Координата текущего объекта
     * \return bool
     */
    bool isPlaceCompareWalls(Coordinates *c);

    /*!
     * \brief Метод сравнивает координаты центров двух шаров
     *
     *	если между ними в сумму будет меньше 50, то метод
     * возвращает false.
     *
     * \param c1 Координаты первого объекта
     * \param c2 Координаты второго объекта
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


    std::map<int, Coordinates*> allCoordinates; //! Контенер мапа
};


#endif // COORDIANTESCONTAINER_H
