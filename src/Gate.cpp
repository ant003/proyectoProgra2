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

#include <iostream>

GateManager::GateManager()
{
	for(int index = 0; index < 4; ++index)
		gates[index] = generateGate();
}

void GateManager::setUpSharedRenderer(QSvgRenderer* svgRenderer)
{
	for(int index = 0; index < 4; ++index)
		gates[index]->setSharedRenderer(svgRenderer);
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
	Gate* product = nullptr;
    int value = static_cast<int>((qrand() % 9));
    //std::cout << value << std::endl;
    //int value = 8;
	switch(value)
	{
		case(0):
			product = new Gate("Number7");
	std::cout << "generando 7" << std::endl;
			product->setValue(-7);
		break;
		case(1):
			product = new Gate("RomanXI");
	std::cout << "generando XI" << std::endl;
			product->setValue(-11);
		case(2):
			product = new Gate("CharF");
	std::cout << "generando F" << std::endl;
			product->setValue(-7);
		break;
		case(3):
			product = new Gate("CharN");
	std::cout << "generando N" << std::endl;
			product->setValue(-16);
		break;
		case(4):
			product = new Gate("Number2");
	std::cout << "generando 2" << std::endl;
			product->setValue(-2);
		break;
		case(5):
			product = new Gate("RomanXIX");
	std::cout << "generando XIX" << std::endl;
			product->setValue(-19);
		case(6):
			product = new Gate("Number4");
	std::cout << "generando 4" << std::endl;
			product->setValue(-4);
		break;
		case(7):
			product = new Gate("RomanVII");
	std::cout << "generando VII" << std::endl;
			product->setValue(-7);
		break;
		case(8):
			product = new Gate("CharA");
	std::cout << "generando A" << std::endl;
			product->setValue(-1);
		break;
	}
	return product;
}
