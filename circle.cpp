#include "circle.h"

Circle::Circle(QObject *parent) : QObject(parent), QGraphicsItem()
{
    pressed = false;
}

Circle::~Circle()
{

}

QRectF Circle::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(pressed)
    {
        painter->setBrush(Qt::black);
    }
    else
    {
        painter->setBrush(Qt::red);
    }

    painter->drawEllipse(boundingRect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Circle::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
    QGraphicsItem::mousePressEvent(event);
}

void Circle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void Circle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
