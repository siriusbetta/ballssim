#include "mycustomscene.h"

MyCustomScene::MyCustomScene(QObject *parent) :
    QGraphicsScene(parent)
{
}

MyCustomScene::MyCustomScene(BallsContainer *balls, CoordiantesContainer *coordinats) : p_balls(balls),
    p_coordiantes(coordinats)
{

}

MyCustomScene::~MyCustomScene()
{
}

void MyCustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    int x = event->scenePos().x();
    int y = event->scenePos().y();

    if(p_coordiantes->isAvaiblePos(new Coordinates(x, y)))
    {
        ball = new Ball();
        int id = p_balls->getLastId() + 1;
        ball->setId(id);
        this->addItem(ball);
        p_balls->addItem(id, ball);
        p_coordiantes->setCoordinates(id, new Coordinates(event->scenePos().x(), event->scenePos().y()));
        ball->setPos(event->scenePos().x(), event->scenePos().y());
    }
    QGraphicsScene::mousePressEvent(event);
}
