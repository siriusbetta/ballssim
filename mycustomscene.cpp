#include "mycustomscene.h"

MyCustomScene::MyCustomScene(QObject *parent) :
    QGraphicsScene(parent)
{
}

MyCustomScene::MyCustomScene(BallsContainer *balls) : p_balls(balls)
{
}

MyCustomScene::~MyCustomScene()
{
}

void MyCustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    ball = new Ball();
    int id = p_balls->getLastId() + 1;
    ball->setId(id);
    this->addItem(ball);
    p_balls->addItem(id, ball);
    ball->setPos(event->scenePos().x(), event->scenePos().y());
    QGraphicsScene::mousePressEvent(event);
}
