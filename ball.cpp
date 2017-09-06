#include "ball.h"

Ball::Ball(QObject *parent) : QObject(parent),
    QGraphicsItem()
{
}

Ball::~Ball()
{
}

int Ball::getId()
{
    return m_id;
}

void Ball::setId(int id)
{
    m_id = id;
}

QRectF Ball::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Ball::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
    QGraphicsItem::mousePressEvent(event);
}

void Ball::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void Ball::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
