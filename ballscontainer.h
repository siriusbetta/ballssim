#ifndef BALLSCONTAINER_H
#define BALLSCONTAINER_H

#include <map>
#include <ball.h>

class BallsContainer
{
public:

    BallsContainer();

    ~BallsContainer();

    void addItem(int id, Ball *ball);

    Ball* getItem(int id);

    int getLastId();

    std::map<int, Ball*> balls;
};

#endif // BALLSCONTAINER_H
