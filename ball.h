#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

#include "coordinates.h"

class Ball : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    explicit Ball(QObject *parent = 0);

    ~Ball();

    QRectF boundingRect() const;

    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getId();

    void setId(int id);

    void move(Coordinates & c);

    int m_id;

signals:
    
public slots:

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // BALL_H
