#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "coordinatescontainer.h"
#include "coordinates.h"

class Collisions
{
public:
    Collisions();

    /*!
     * @brief Cheking aviability to placement ball in scene with current coordinates
     *
     * @param c current coordinates
     * @return bool
     */
    static bool isAvaiblePos(Coordinates &c);

    /*!
     * @brief Checks coordinates compare other balls coordiants
     *
     * @param c current coordiants
     * @return bool
     */
   static bool isPlaceCompareOtherBalls(Coordinates &c);

     /*!
     * @brief Checks place between two balls if there are not enough place  (50) for
     *  placement two balss return false
     *
     * @param c1 First coordiants
     * @param c2 Second coordiants
     *
     *	@return bool
     */
    static bool hasEnoughPlaceBetweenTwoBalls(Coordinates &c1, Coordinates &c2);

    /*!
     * \brief Compare current coordinates with wall coordinates
     *
     * \param c current balls coordinates
     * \return bool
     */
    static bool isPlaceCompareWalls(Coordinates &c);

     /*!
     * @breaf Checks lentgth between two coordinates
     *
     *	if length less or equal 25 means that given coordinate lays into the ball
     *
     * @param c1
     * @param c2
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
