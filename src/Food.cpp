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
	
	//Connect
	QTimer* timer = new QTimer(this);
	connect(timer,SIGNAL(timeout()),this,SLOT(move()));
	timer->start(50);
}

Food::~Food()
{
}


//move food down
void Food::move()
{
	QList<QGraphicsItem*> items = collidingItems();
	for ( QGraphicsItem* item : items )
	{
		// If a graphic item is an snek remove it from scene
		if ( dynamic_cast<Snek*>(item) )
		{
			
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
	// We chose a random initial position within the screen
	qreal x = qrand() % int(scene()->width() - this->boundingRect().width());
	qreal y = 0;
	
	setPos( QPointF(x, y) );
}

