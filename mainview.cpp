#include "mainview.h"
#include "collisions.h"
#include <QDebug>
#include "loggingcategories.h"


ViewWindow::ViewWindow( QWidget *parent) : QGraphicsView(parent)
{
    balls = new BallsContainer();

    scene = new SimulationScene(balls);

    setScene(scene);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Stretch the widget content
    setRenderHint(QPainter::Antialiasing);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->setSceneRect(0, 0, 500, 500);
    qInfo(logInfo()) << "Opened" << endl;
}

ViewWindow::~ViewWindow()
{

}
