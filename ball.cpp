#include <QDebug>
#include "loggingcategories.h"
#include "ball.h"
#include "collisions.h"
#include "coordinates.h"
#include "coordiantescontainer.h"

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

void Ball::move(Coordinates &c)
{
    if(Collisions::isBorder(c))
    {
        qInfo(logInfo()) << "id: " << m_id << " x: " << c.getX() << " y: " << c.getY() << endl;
        this->setX(c.getX());
        this->setY(c.getY());
        //this->setPos(mapToScene((double)c.getX(), (double)c.getY()));
        //CoordiantesContainer::Instance().updateItem(m_id, c);
    }
}

void Ball::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if( (event->buttons() & Qt::LeftButton) == Qt::LeftButton)
    {
        Coordinates c(event->scenePos().x(), event->scenePos().y());
        this->setPos(mapToScene(event->pos()));
        CoordiantesContainer::Instance().updateItem(m_id, c);
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void Ball::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        this->setCursor(QCursor(Qt::ClosedHandCursor));
    }
    Q_UNUSED(event);
}

void Ball::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        this->setCursor(QCursor(Qt::ArrowCursor));
    }
    Q_UNUSED(event);
}
