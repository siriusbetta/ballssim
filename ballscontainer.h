#ifndef BALLSCONTAINER_H
#define BALLSCONTAINER_H

#include <map>
#include <ball.h>

/*!
 * @brief class implements balls keeping container for graphic scene
 *
 */
class BallsContainer
{
public:

  /*!
   * BallsContainer c-r
   */
    BallsContainer();

    /*!
     * BallsContainer des-r
     */
    ~BallsContainer();

    /*!
     * Adds ball to the container
     * Checks for ability to placement ball. The place must be no walls or other balls
     * @param id   ball id (using for identification balls coordinates)
     * @param ball balls object
     */
    void addItem(int id, Ball *ball);

    /*!
     * Returns pointer to the ball object
     *
     * @param  id balls id
     * @return    pointer to the balls object
     */
    Ball* getItem(int id);

    /*!
     * Last id
     * @return last id contains in container. zero if empty
     */
    int getLastId();

    /*!
     * remove item by id
     * @param id balls id
     */
    void remove(int id);

    std::map<int, Ball*> balls; /*< container */
};

#endif // BALLSCONTAINER_H
