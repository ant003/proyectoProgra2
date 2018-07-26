#include "Gate.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>
Gate::Gate(const char* id) : FallingObject(id)
{
	setValue(-5);
}

Gate::~Gate() {}

void Gate::setInitialPos(){}

void Gate::setInitialPos(int gateNumber)
{
	qreal x,y;
	switch(gateNumber)
	{
		case(0):
			x = y = 0;
		break;
		case(1):
			x = scene()->width()/3;
			y = 0;
		break;
		case(2):
			x = (2*scene()->width())/3;
			y = 0;
		break;
	}
	setPos(x,y);
}

void Gate::reactTo()
{
	this->touched = true;
	if( before && before->touched == false )
		before->reactTo();
	if( next && next->touched == false )
		next->reactTo();
}

void Gate::setAdjacent( Gate* before, Gate* next )
{
	this->next = next;
	this->before = before;
}
