#ifndef TRAINGLE_H
#define TRAINGLE_H

#include <QGraphicsItem>
#include <QPainter>

class Traingle : public QGraphicsItem
{
public:
    Traingle();
    ~Traingle();

protected:
    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // TRAINGLE_H
