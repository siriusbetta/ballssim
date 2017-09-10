#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QGraphicsView>

#include <viewwindow.h>
#include <mycustomscene.h>
#include <ballscontainer.h>
#include <coordiantescontainer.h>

class ViewWindow : public QGraphicsView
{
    Q_OBJECT
public:
    ViewWindow( QWidget *parent = 0);
    ~ViewWindow();

    MyCustomScene *scene;
    BallsContainer *balls;
    CoordiantesContainer *coordiantes;
};


#endif // VIEWWINDOW_H
