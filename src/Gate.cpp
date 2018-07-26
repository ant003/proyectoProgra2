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
        case(0): /// all the way to the left
			x = y = 0;
		break;
		case(1):
            x = scene()->width()/4; /// mid left
			y = 0;
		break;
		case(2):
            x = scene()->width()/2; /// mid right
			y = 0;
		break;
		case(3):
            x = (3*scene()->width())/4; /// all the way to the right
			y = 0;
		break;
	}
	setPos(x,y);
}

void Gate::reactTo()
{
    /// changed its state to touched and also changes all of the adjacent doors
	this->touched = true;
	if( before && before->touched == false )
		before->reactTo();
	if( next && next->touched == false )
		next->reactTo();
}

#include <iostream>

GateManager::GateManager()
{
    /// Sets all the pointers to a random gate and sets the adjacent pointers
    Gate* previousGate = nullptr;
	for(int index = 0; index < 4; ++index)
    {
        gates[index] = generateGate();
        gates[index]->before = previousGate;
        if( previousGate ) previousGate->next = gates[index];
        previousGate = gates[index];
    }
}

void GateManager::setUpSharedRenderer(QSvgRenderer* svgRenderer)
{
    /// Sets up the svgRenderer
	for(int index = 0; index < 4; ++index)
		gates[index]->setSharedRenderer(svgRenderer);
}

void GateManager::addToScene(QGraphicsScene *scene)
{
    /// Adds all the elements of the array to the scene
	for(int index = 0; index < 4; ++index)
	{
		scene->addItem(gates[index]);
		gates[index]->setInitialPos(index);
	}
}

Gate* GateManager::generateGate()
{
    /// Chooses a gate from a random number
	Gate* product = nullptr;
    int value = (qrand() % 9);
    std::cout << value << std::endl;
    //int value = 8;
	switch(value)
	{
		case(0):
			product = new Gate("Number7");
	std::cout << "generando 7" << std::endl;
            product->setValue(-7); //-7
		break;
		case(1):
			product = new Gate("RomanXI");
	std::cout << "generando XI" << std::endl;
            product->setValue(-11); //-11
         break;
		case(2):
			product = new Gate("CharF");
	std::cout << "generando F" << std::endl;
            product->setValue(-7); //-7
		break;
		case(3):
			product = new Gate("CharN");
	std::cout << "generando N" << std::endl;
            product->setValue(-16); //-16
		break;
		case(4):
			product = new Gate("Number2");
	std::cout << "generando 2" << std::endl;
            product->setValue(-2); //-2
		break;
		case(5):
			product = new Gate("RomanXIX");
	std::cout << "generando XIX" << std::endl;
            product->setValue(-19); //-19
        break;
		case(6):
			product = new Gate("Number4");
	std::cout << "generando 4" << std::endl;
            product->setValue(-4); //-4
		break;
		case(7):
			product = new Gate("RomanVII");
	std::cout << "generando VII" << std::endl;
            product->setValue(-7); //-7
		break;
		case(8):
			product = new Gate("CharA");
	std::cout << "generando A" << std::endl;
            product->setValue(-1); // -1
		break;
	}
	return product;
}
