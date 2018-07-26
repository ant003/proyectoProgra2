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
			x = scene()->width()/4;
			y = 0;
		break;
		case(2):
			x = scene()->width()/2;
			y = 0;
		break;
		case(3):
			x = (3*scene()->width())/4;
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

GateManager::GateManager()
{
	for(int index = 0; index < 4; ++index)
		gates[index] = generateGate();
}

void GateManager::addToScene(QGraphicsScene *scene)
{
	for(int index = 0; index < 4; ++index)
	{
		scene->addItem(gates[index]);
		gates[index]->setInitialPos(index);
	}
}

Gate* GateManager::generateGate()
{ // 7 XI F N 2 XIX 4 VII A
	Gate* newGate = nullptr;
	int value;
	switch(value)
	{
		case(0):
			newGate = new Gate("Number7");
			newGate->setValue(7);
		break;
		case(1):
			newGate = new Gate("RomanXI");
			newGate->setValue(11);
		case(2):
			newGate = new Gate("CharF");
			newGate->setValue(7);
		break;
		case(3):
			newGate = new Gate("CharN");
			newGate->setValue(16);
		break;
		case(4):
			newGate = new Gate("Number2");
			newGate->setValue(2);
		break;
		case(5):
			newGate = new Gate("RomanXIX");
			newGate->setValue(19);
		case(6):
			newGate = new Gate("Number4");
			newGate->setValue(4);
		break;
		case(7):
			newGate = new Gate("RomanVII");
			newGate->setValue(7);
		break;
		case(8):
			newGate = new Gate("CharA");
			newGate->setValue(1);
		break;
	}
	return newGate;
}
