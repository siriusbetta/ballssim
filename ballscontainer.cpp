#include "ballscontainer.h"

BallsContainer::BallsContainer()
{
}

BallsContainer::~BallsContainer()
{

}

Ball* BallsContainer::getItem(int id)
{
    return balls[id];
}

void BallsContainer::addItem(int id, Ball *ball)
{
    balls.insert(std::make_pair(id, ball));
}

int BallsContainer::getLastId()
{
    return balls.end()->first;
}

void BallsContainer::remove(int id)
{
    balls.erase(id);
}
