#ifndef PHYSICSTHREAD_H
#define PHYSICSTHREAD_H


class PhysicsThread
{
public:

    PhysicsThread();

    ~PhysicsThread();

    void operator()();

    double getForce(int a);

    void physicsCalculation();
};

#endif // PHYSICSTHREAD_H
