#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QGraphicsView>

#include <mainview.h>
#include <simulationscene.h>
#include <ballscontainer.h>
#include <coordinatescontainer.h>

class ViewWindow : public QGraphicsView
{
    Q_OBJECT
public:
    ViewWindow( QWidget *parent = 0);
    ~ViewWindow();

    SimulationScene *scene;
    BallsContainer *balls;
    CoordinatesContainer *coordiantes;
};

#endif // MAINVIEW_H
