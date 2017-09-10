/*!
 *	@brief implements container for Coordinates
 * the methods are threads safelly, because the container uses for sharing
 * data between graphic main thread and calcuations thread
 *
 */
#ifndef COORDINATESCONTAINER_H
#define COORDINATESCONTAINER_H

#include <map>
#include <algorithm>
#include <mutex>
#include "coordinates.h"

class CoordinatesContainer
{
public:
  /*!
   * Singleton. Returns link someself
   * @return
   */
    static CoordinatesContainer& Instance()
    {
        static CoordinatesContainer c;
        return c;
    }

    /*!
     * @brief Adds coordiantes to the container

     * @param id ball id
     * @param coordinates
     */
    void setCoordinates(int id, Coordinates &coordinates);

    /*!
     * @brief Returns coordinats from container by id
     *
     * @return Coordinates
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

    /*!
     * updates coordinates in the caontainer by balls id
     * @param id
     * @param coordinates
     */
    void updateItem(int id, Coordinates &coordinates);

    /*!
     * @brief Looking for a ball id by given coordinates
     *
     * @param coordiantes
     */
    int findIdByCoordinates(Coordinates& coordinates);

    /*!
     * removed all items from container
     */
    void erase();

    /*!
     * returns container
     *
     * @param map where keeps all coordinates
     */
    std::map<int, Coordinates> getContainer();

    /*!
     * Sets container
     * @param container map
     */
    void setContainer(std::map<int, Coordinates>& container);

    std::mutex mutex; /*< mutex locker */

private:
    CoordinatesContainer();

    std::map<int, Coordinates> allCoordinates; /*< container*/
};


#endif // COORDINATESCONTAINER_H
