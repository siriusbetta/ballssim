#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "coordiantescontainer.h"
#include "coordinates.h"

class Collisions
{
public:
    Collisions();

/*!
     * \brief Проверяет допустимость расположение нового шара относительно стен и других шаров
     *
     * \param c Координата текущего объекта
     * \return bool
     */
    static bool isAvaiblePos(CoordiantesContainer *cont, Coordinates *c);

    /*!
     * \brief Проверяет допустимость расположения отностильно других шаров на поле симуляции текущего шара
     *
     * метод обходит через все элеметы мапы и сравнивает
     *
     * \param c Координата текущего объекта
     * \return bool
     */
   static bool isPlaceCompareOtherBalls(CoordiantesContainer *cont, Coordinates *c);
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
    static bool hasEnoughPlaceBetweenTwoBalls(Coordinates *c1, Coordinates *c2);

    /*!
     * \brief Метод сравнивает данную координату относительно границ поля симуляции
     *
     * если до стены муньше 25 или больше 575 по обоим координатам то метод возвращает false
     *
     * \param c Координата текущего объекта
     * \return bool
     */
    static bool isPlaceCompareWalls(Coordinates *c);

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
    static bool isCoordinateLayInTheBall(Coordinates *c, Coordinates *b);

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
    static bool isLengthBetweenTwoBallsMoreThenLength(Coordinates *c1, Coordinates *c2, int length);


    static int width;
    static int height;
};

#endif // COLLISIONS_H
