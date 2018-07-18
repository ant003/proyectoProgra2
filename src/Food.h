#ifndef FOOD_H
#define FOOD_H
#include "AnimatedObject.h"

class QPropertyAnimation;

class QMouseEvent;

class Food : public AnimatedObject
{
	Q_OBJECT
	Q_DISABLE_COPY(Food)
	
	/// Create a position property to animate the movement of this item
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
	
protected:
	/// Constructor
	/// Animates the food moving around the screen
	QPropertyAnimation* moveAnimation = nullptr;
public:
	Food();
	
	~Food();
	/// Set the initial position of this item
	void setInitialPos();
	/// Called when this item is clicked or tapped by the user
	//virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
public slots:
	void move();
	
};

#endif // FOOD_H
