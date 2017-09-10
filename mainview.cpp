#include "mainview.h"
#include "collisions.h"
#include <QDebug>
#include "loggingcategories.h"


ViewWindow::ViewWindow( QWidget *parent) : QGraphicsView(parent)
{
    balls = new BallsContainer();

    scene = new SimulationScene(balls);
    //triangle = new Traingle();

    setScene(scene);
    //setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Stretch the widget content
    setRenderHint(QPainter::Antialiasing);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //scene->setSceneRect(-300, -300, 600, 600);
    //scene->setSceneRect(0, 0, this->width() - 50, this->height() - 50);
    scene->setSceneRect(0, 0, 500, 500);
    //scene->installEventFilter(this);
    qInfo(logInfo()) << "Opened" << endl;

}

ViewWindow::~ViewWindow()
{

}


