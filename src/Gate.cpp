#include "Gate.h"

Gate::Gate(const char* id) : FallingObject(id)
{
	
}

Gate::~Gate() {}

void Gate::setInitialPos(qreal x, qreal y)
{
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
