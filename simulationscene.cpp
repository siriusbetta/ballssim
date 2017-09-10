#include "simulationscene.h"
#include <QDebug>
#include <QMouseEvent>
#include <thread>
#include "loggingcategories.h"
#include "physicsthread.h"

SimulationScene::SimulationScene(QObject *parent) :
    QGraphicsScene(parent)
{
}

SimulationScene::SimulationScene(BallsContainer *balls) : allBalls(balls)
{
    std::srand(std::time(NULL));

    //addRect(0, 0, 520, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray));
    //addRect(0, 0, 20, 520, QPen(Qt::NoPen), QBrush(Qt::darkGray));
    //addRect(0, 500, 520, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray));
    //addRect(500, 0, 20, 520, QPen(Qt::NoPen), QBrush(Qt::darkGray));
    //addRect(170, 250, 180, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray));
    //addRect(250, 170, 20, 180, QPen(Qt::NoPen), QBrush(Qt::darkGray));

    for(int i = 1; i < 4; ++i)
    {
        int randX = 50 + std::rand() % static_cast<int>(450 - 1);
        int randY = 50 + std::rand() % static_cast<int>(450 - 1);
        Coordinates c( randX, randY);
        addBall(c);
    }

    sceneTimer = new QTimer();
    connect(sceneTimer, &QTimer::timeout, this, SimulationScene::slotAnimation);


    sceneTimer->start(100);
}

SimulationScene::~SimulationScene()
{
}


void SimulationScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Coordinates c(event->scenePos().x(), event->scenePos().y());

    if(event->button() == Qt::LeftButton)
    {
        addBall(c);
    }

    if(event->button() == Qt::RightButton)
    {
        removeBall(c);
    }

    QGraphicsScene::mousePressEvent(event);
}

void SimulationScene::addBall(Coordinates &c)
{
    if( Collisions::isAvaiblePos(c))
    {
        ball = new Ball();
        int id = allBalls->getLastId() + 1;

        ball->setId(id);
        this->addItem(ball);
        allBalls->addItem(id, ball);
        CoordinatesContainer::Instance().setCoordinates(id,c);
        ball->setPos(ball->mapToScene(c.getX() - 25, c.getY() - 25));
    }
}

void SimulationScene::removeBall(Coordinates &c)
{
   int id = CoordinatesContainer::Instance().findIdByCoordinates(c);
   Ball *ball = allBalls->getItem(id);

   this->removeItem(ball);
   allBalls->remove(id);
   CoordinatesContainer::Instance().removeItem(id);
}

void SimulationScene::slotAnimation()
{
    std::map<int, Coordinates> coordinates = CoordinatesContainer::Instance().getContainer();
    std::map<int, Coordinates>::iterator it;
    Ball *ball;

    for(it = coordinates.begin(); it != coordinates.end(); ++it)
    {
        int id = it->first;
        ball = allBalls->getItem(id);
        ball->move(it->second);
    }
}

