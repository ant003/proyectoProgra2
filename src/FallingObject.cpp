#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QTimer>
#include <QList>
#include <QString>
#include "FallingObject.h"
#include "Snek.h"
#include "Game.h"

FallingObject::FallingObject( const char* name )
{
	// The name of the svg element
	setElementId( QString(name) );
	setElementId( name );
	touched = false;
	speed = 1;
	//Connect
	QTimer* timer = new QTimer(this);
	connect(timer,SIGNAL(timeout()),this,SLOT(move()));
	timer->start(50);
}

FallingObject::~FallingObject()
{
}

void FallingObject::move()
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
	setPos(x(),y()+(5 * speed ));
	if(pos().y() > scene()->height())
	{
		scene()->removeItem(this);
		delete this;
	}
}

void FallingObject::setInitialPos()
{

	qreal x = qrand() % int(scene()->width() - this->boundingRect().width());
	qreal y = 0;
	setPos( QPointF(x, y) );
}

bool FallingObject::getStatus() const { return touched; }

void FallingObject::setStatus(bool status){ this->touched = status; }

void FallingObject::setSpeed( double speed ){ this->speed = speed; }


