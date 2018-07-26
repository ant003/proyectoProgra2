#ifndef FOOD_H
#define FOOD_H
#include "FallingObject.h"

class QPropertyAnimation;

class Food : public FallingObject
{
	Q_OBJECT
	Q_DISABLE_COPY(Food)
	

    /// provides inter-object communication via signals and slots.
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
	
protected:

    /// Animates the food moving around the screen
	QPropertyAnimation* moveAnimation = nullptr;
	
public:
    /// Default consctructor
	Food();
	
    /// Default destructor
	~Food();
	
    /// Selects a random position as its initial point at the highest y at view
	virtual void setInitialPos();
	
    /// method that specifies how the gate should react if it collides with another item
	virtual void reactTo();
};

#endif // FOOD_H
