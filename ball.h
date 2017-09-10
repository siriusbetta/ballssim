#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

#include "coordinates.h"
/*!
 * @brief class implementation the Ball
 *        graphics representaoin
 *
 * @param  QGraphicsItem is a QT grphic object
 */
class Ball : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    explicit Ball(QObject *parent = 0);

    ~Ball();

    /*!
     * @brief returns area where located painted item
     * @return qtobject rectangle
     */
    QRectF boundingRect() const;

    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /*!
     * returns id of the Ball
     *
     * @return int balls id
     */
    int getId();

    /**
     * setting of balls id
     *
     * @param id
     */
    void setId(int id);

    /*!
     * Updates current balls coordinates with new one
     *
     * @param c new coordinates
     */
    void move(Coordinates & c);

    int m_id; /*< balls id*/

signals:

public slots:

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // BALL_H
