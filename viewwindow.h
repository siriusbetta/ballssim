#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QGraphicsView>
#include <viewwindow.h>
#include <traingle.h>
#include <circle.h>
#include <mycustomscene.h>

class ViewWindow : public QGraphicsView
{
    Q_OBJECT
public:
    ViewWindow( QWidget *parent = 0);
    ~ViewWindow();

    QGraphicsScene *scene;
    Traingle *triangle;
    Circle *circ;

};

#endif // VIEWWINDOW_H
