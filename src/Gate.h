#ifndef GATE_H
#define GATE_H
#include "FallingObject.h"
#include <string>
class QPropertyAnimation;
class QGraphicsTextItem;
class Gate : public FallingObject
{

    friend class GateManager;

	Q_OBJECT
	Q_DISABLE_COPY(Gate)
	
    /// Provides inter-object communication via signals and slots.
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
	
protected:
    /// Animates the gates moving around the screen
	QPropertyAnimation* moveAnimation = nullptr;
	
	Gate* next = nullptr;
	
	Gate* before = nullptr;
	
public:
    /// Default constructor that creates a gate with a specific id
	Gate(const char* id);
	
    /// Default destructor
	virtual ~Gate();
	
    /// Sets the initial position of the gate from 4 possible positions
	virtual void setInitialPos(int gateNumber);
	
    /// Default set initial position
	virtual void setInitialPos();
	
    /// method that specifies how the gate should react if it collides with another item
	virtual void reactTo();
	
};


class GateManager
{
public:
	GateManager();
	
    /// add all its items to the scene
	void addToScene(QGraphicsScene* scene);
	
    /// sets up all the svgRenderer
	void setUpSharedRenderer(QSvgRenderer* svgRenderer);
	
private:
	Gate* gates[4] = {nullptr,nullptr,nullptr,nullptr};
	
    /// generates a random gate
	Gate* generateGate();
};
//class NumericGate : public Gate
//{
//private:
//	std::string id[3] = {"Number2","Number4","Number7"};
//	int value[3] = {2,4,7};
	
//public:
//	NumericGate(int index) : Gate(id[index].c_str()){ setValue(value[index]); }
//};

//class CharacterGate : public Gate
//{
//private:
//	std::string id[3] = {"CharA","CharF","CharN"};
//	int value[3] = {1,7,16};
	
//public:
//	CharacterGate(int index) : Gate(id[index].c_str()){ setValue(value[index]); }
//};

//class RomanGate : public Gate
//{
//private:
//	std::string id[3] = {"RomanVII","RomanXIX","RomanXI"};
//	int value[3] = {7,19,11};
	
//public:
//	RomanGate(int index) : Gate(id[index].c_str()){ setValue(value[index]); }
//};

#endif // GATE_H
