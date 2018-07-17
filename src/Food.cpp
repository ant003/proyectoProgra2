#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>

#include "Food.h"

Food::Food(QGraphicsItem* parent)
    : QGraphicsSvgItem(parent)
{
    // The name of the svg element
    setElementId("food");

    //Connect
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

//move food down
void Food::move()
{
    setPos(x(),y()+5);
}

void Food::setInitialPos()
{
    // We chose a random initial position within the screen
    qreal x = qrand() % int(scene()->width() - this->boundingRect().width());
    qreal y = 0;

    setPos( QPointF(x, y) );
}

