#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QTimer>
#include <QList>
#include "Snek.h"
#include "Game.h"

#include "Food.h"


Food::Food()
{
	// The name of the svg element
	setElementId( QString("food"));
	setElementId("food");
	touched = false;
	//Connect
	QTimer* timer = new QTimer(this);
	connect(timer,SIGNAL(timeout()),this,SLOT(move()));
	timer->start(50);
}

Food::~Food()
{
}

void Food::move()
{
	QList<QGraphicsItem*> items = collidingItems();
	for ( QGraphicsItem* item : items )
	{

		if ( dynamic_cast<Snek*>(item) )
		{
			this->touched = true;
			this->deleteLater();
			return;
		}
		
	}
	setPos(x(),y()+5);
	if(pos().y() > scene()->height())
	{
		scene()->removeItem(this);
		delete this;
	}
}

void Food::setInitialPos()
{

	qreal x = qrand() % int(scene()->width() - this->boundingRect().width());
	qreal y = 0;
	
	setPos( QPointF(x, y) );
}

bool Food::getStatus() const { return touched; }

void Food::setStatus(bool status){ this->touched = status; }

