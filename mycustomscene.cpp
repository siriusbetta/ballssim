#include "mycustomscene.h"

MyCustomScene::MyCustomScene(QObject *parent) :
    QGraphicsScene(parent)
{
}

MyCustomScene::~MyCustomScene()
{
}

void MyCustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    circle = new Circle();
    this->addItem(circle);
    circle->setPos(event->scenePos().x(), event->scenePos().y());
    QGraphicsScene::mousePressEvent(event);
}
