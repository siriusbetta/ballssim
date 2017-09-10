#ifndef SIMULATIONSCENE_H
#define SIMULATIONSCENE_H

#include <QGraphicsScene>
#include <QTimer>

#include <ballscontainer.h>
#include <coordinatescontainer.h>
#include <ball.h>
#include "collisions.h"
#include "coordinates.h"

class SimulationScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit SimulationScene(QObject *parent = 0);
    SimulationScene(BallsContainer *balls);

    ~SimulationScene();

    Ball *ball;

    BallsContainer *allBalls;

    void addBall(Coordinates &c);

    void removeBall(Coordinates &c);

private slots:

    void slotAnimation();

private:
    QTimer *sceneTimer;


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif //SIMULATIONSCENE_H
