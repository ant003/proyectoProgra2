#ifndef GATE_H
#define GATE_H
#include "FallingObject.h"
#include <string>
class QPropertyAnimation;

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
	
	Gate* next;
	
	Gate* before;
	
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
	virtual void setInitialPos(qreal x, qreal y);
	
	virtual void reactTo();
	
	virtual void setAdjacent(Gate* before, Gate* next );
	
};

class NumericGate : public Gate
{
private:
	std::string id[7] = {"Numeric1","Numeric2","Numeric3","Numeric4","Numeric5","Numeric6","Numeric7"};
	int value[7] = {1,2,3,4,5,6,7};
	
public:
	NumericGate(int index) : Gate(id[index].c_str()){ setValue(value[index]); }
};

class CharacterGate : public Gate
{
private:
	std::string id[5] = {"CharacterA","CharacterF","CharacterC","CharacterN","CharacterG"};
	int value[5] = {1,6,3,14,7};
	
public:
	CharacterGate(int index) : Gate(id[index].c_str()){ setValue(value[index]); }
};

class RomanGate : public Gate
{
private:
	std::string id[4] = {"RomanVII","RomanIV","RomanXIX","RomanXI"};
	int value[4] = {7,4,19,11};
	
public:
	RomanGate(int index) : Gate(id[index].c_str()){ setValue(value[index]); }
};

#endif // GATE_H
