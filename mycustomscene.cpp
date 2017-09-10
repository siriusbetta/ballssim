#include "mycustomscene.h"
#include <QDebug>
#include <QMouseEvent>
#include <thread>
#include "loggingcategories.h"
#include "physicsthread.h"

MyCustomScene::MyCustomScene(QObject *parent) :
    QGraphicsScene(parent)
{
}

MyCustomScene::MyCustomScene(BallsContainer *balls) : p_balls(balls)
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
    connect(sceneTimer, &QTimer::timeout, this, MyCustomScene::slotAnimation);


    sceneTimer->start(100);
}

MyCustomScene::~MyCustomScene()
{
}


void MyCustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    int x = event->scenePos().x();
    int y = event->scenePos().y();

    Coordinates c(x, y);

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



void MyCustomScene::addBall(Coordinates &c)
{
    if( Collisions::isAvaiblePos(c))
    {
        ball = new Ball();
        int id = p_balls->getLastId() + 1;
        ball->setId(id);
        ball->installEventFilter(this);
        this->addItem(ball);
        p_balls->addItem(id, ball);
        CoordiantesContainer::Instance().setCoordinates(id,c);
        ball->setPos(ball->mapToScene(c.getX() - 25, c.getY() - 25));
    }
}

void MyCustomScene::removeBall(Coordinates &c)
{
   int id = CoordiantesContainer::Instance().findIdByCoordinates(c);
   Ball *ball = p_balls->getItem(id);
   this->removeItem(ball);
   p_balls->remove(id);

   CoordiantesContainer::Instance().removeItem(id);
}


void MyCustomScene::slotAnimation()
{
    std::map<int, Coordinates> coordinates = CoordiantesContainer::Instance().getContainer();
    std::map<int, Coordinates>::iterator it;
    Ball *ball;

    for(it = coordinates.begin(); it != coordinates.end(); ++it)
    {
        int id = it->first;
        ball = p_balls->getItem(id);
        ball->move(it->second);
    }
}

/*
bool MyCustomScene::eventFilter(QObject *watched, QEvent *event)
{
    qInfo(logInfo()) << "Scene received" << endl;
    if(event->type() == QEvent::MouseButtonPress)
    {
        qInfo(logInfo()) << "Scene received" << endl;
    }
    return MyCustomScene::eventFilter(watched, event);
}
*/
