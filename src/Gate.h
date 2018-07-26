#ifndef GATE_H
#define GATE_H
#include "FallingObject.h"
#include <string>
class QPropertyAnimation;
class QGraphicsTextItem;
class Gate : public FallingObject
{
	Q_OBJECT
	Q_DISABLE_COPY(Gate)
	
	/**
	  * @brief Create a position property to animate the movement of this item
	  * @details provides inter-object communication via signals and slots.
	  */
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
	
protected:
	/**
	  * @brief Animates the gates moving around the screen
	  * @details
	  */
	QPropertyAnimation* moveAnimation = nullptr;
	
	Gate* next = nullptr;
	
	Gate* before = nullptr;
	
public:
	/**
	 * @brief Food default constructor
	 */
	Gate(const char* id);
	
	/**
	  * @brief Food default destructor
	  */
	virtual ~Gate();
	
	/**
	 * @brief setInitialPos Set the initial position of this item
	 * @details it chose a random initial position for the X axis within the screen, the y axis keeps always on 0
	 */
	virtual void setInitialPos(int gateNumber);
	
	virtual void setInitialPos();
	
	virtual void reactTo();
	
	virtual void setAdjacent(Gate* before, Gate* next );
	
};


class GateManager
{
public:
	GateManager();
	
	void addToScene(QGraphicsScene* scene);
	
private:
	Gate* gates[4] = {nullptr,nullptr,nullptr,nullptr};
	
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
