#include "traingle.h"

Traingle::Traingle() : QGraphicsItem()
{
}

Traingle::~Traingle()
{
}

QRectF Traingle::boundingRect() const
{
    return QRectF(-25, -40, 50, 80);
}

void Traingle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;
    polygon << QPoint(0, -40) << QPoint(25, 40) << QPoint(-25, 40);
    painter->setBrush(Qt::red);

    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
