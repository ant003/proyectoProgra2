#include <QGraphicsScene>
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
	
	// Its attributes
	this->touched = false;
	this->speed = 1;
	this->value = 1;
	
	//starts a timer so the object will move every time the timer sends a signal
	QTimer* timer = new QTimer(this);
	connect(timer,SIGNAL(timeout()),this,SLOT(move()));
	timer->start(25);
}

FallingObject::~FallingObject()
{
}

void FallingObject::move()
{
	// Changes the y position of the object so it falls down at certain speed
	setPos(x(),y()+(5 + speed ));
	if(pos().y() > scene()->height())
	{
		// if the object has reached the end of the view it gets deleted
        //scene()->removeItem(this);
        //this->deleteLater();
        this->destroy(true,true);
        //delete this;
	}
}

bool FallingObject::getStatus() const { return touched; }

void FallingObject::setSpeed( double speed ){ this->speed = speed; }

int FallingObject::getValue() const { return value; }

void FallingObject::setValue(int value) { this->value = value; }


