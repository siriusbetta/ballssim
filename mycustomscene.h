#ifndef MYCUSTOMSCENE_H
#define MYCUSTOMSCENE_H

#include <QGraphicsScene>

#include <ballscontainer.h>
#include <coordiantescontainer.h>
#include <ball.h>

class MyCustomScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyCustomScene(QObject *parent = 0);
    MyCustomScene(BallsContainer *balls, CoordiantesContainer *coordinates);

    ~MyCustomScene();

    Ball *ball;

    BallsContainer *p_balls;
    CoordiantesContainer *p_coordiantes;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYCUSTOMSCENE_H
