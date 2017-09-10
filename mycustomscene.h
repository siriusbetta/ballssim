#ifndef MYCUSTOMSCENE_H
#define MYCUSTOMSCENE_H

#include <QGraphicsScene>
#include <QTimer>

#include <ballscontainer.h>
#include <coordiantescontainer.h>
#include <ball.h>
#include "collisions.h"
#include "coordinates.h"

class MyCustomScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyCustomScene(QObject *parent = 0);
    MyCustomScene(BallsContainer *balls);

    ~MyCustomScene();

    Ball *ball;

    BallsContainer *p_balls;

    void addBall(Coordinates &c);

    void removeBall(Coordinates &c);

private slots:

    void slotAnimation();

private:
    QTimer *sceneTimer;


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYCUSTOMSCENE_H
