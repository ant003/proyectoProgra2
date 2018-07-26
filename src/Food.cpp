#include <QApplication>
#include <QTimer>
#include <QList>
#include "Snek.h"
#include "Game.h"
#include <QGraphicsScene>
#include "Food.h"


Food::Food() : FallingObject("food"){}

Food::~Food(){}

void Food::setInitialPos()
{
	// the object will start at a random position
	qreal x = qrand() % int(scene()->width() - this->boundingRect().width());
	qreal y = 0;
	setPos( QPointF(x, y) );
}

void Food::reactTo()
{
	// if it collides with the snek this object will change its state and will be hided
	this->touched = true;
    this->destroy(true,true);
    //this->deleteLater(); // posible crasheo
}
