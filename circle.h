#ifndef CIRCLE_H
#define CIRCLE_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

#include <QPainter>
#include <QWidget>

class Circle : public QObject,  public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Circle(QObject *parent = 0);

    ~Circle();

    bool pressed;

    QRectF boundingRect() const;

    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // CIRCLE_H
