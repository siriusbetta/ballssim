#ifndef PHYSICSTHREAD_H
#define PHYSICSTHREAD_H

/*!
 * Thread where coordinates and movings calculates
 */
class PhysicsThread
{
public:

  /*!
   * PhysicsThread c-r
   */
    PhysicsThread();

    /*!
     * PhysicsThread dest-r
     */
    ~PhysicsThread();

    /*!
     * running thread operator
     */
    void operator()();

    /*!
     * calculates force between bals
     *
     * @param  a length between two balls
     * @return   value of force
     */
    double getForce(int a);

    /*!
     * Processes all movings every 500 mcs
     */
    void physicsCalculation();
};

#endif // PHYSICSTHREAD_H
