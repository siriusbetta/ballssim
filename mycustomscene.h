#ifndef MYCUSTOMSCENE_H
#define MYCUSTOMSCENE_H

#include <QGraphicsScene>

#include <circle.h>

class MyCustomScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyCustomScene(QObject *parent = 0);
    ~MyCustomScene();

    Circle *circle;



protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYCUSTOMSCENE_H
