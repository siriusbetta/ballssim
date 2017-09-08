#include "viewwindow.h"


ViewWindow::ViewWindow( QWidget *parent) : QGraphicsView(parent)
{
    balls = new BallsContainer();
    coordiantes = new CoordiantesContainer();

    scene = new MyCustomScene(balls, coordiantes);
    //triangle = new Traingle();

    setScene(scene);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Stretch the widget content
    setRenderHint(QPainter::Antialiasing);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //scene->setSceneRect(-300, -300, 600, 600);
    //scene->setSceneRect(0, 0, this->width() - 50, this->height() - 50);
    scene->setSceneRect(0, 0, 500, 500);

}

ViewWindow::~ViewWindow()
{

}





