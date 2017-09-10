#ifndef PHYSICSTHREAD_H
#define PHYSICSTHREAD_H


class PhysicsThread
{
public:

    PhysicsThread();

    ~PhysicsThread();

    void operator()();

    double getForce(double a);

    void physicsCalculation();
};

#endif // PHYSICSTHREAD_H
