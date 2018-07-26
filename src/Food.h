#ifndef FOOD_H
#define FOOD_H
#include "FallingObject.h"

class QPropertyAnimation;

class Food : public FallingObject
{
	Q_OBJECT
	Q_DISABLE_COPY(Food)
	
	/**
	  * @brief Create a position property to animate the movement of this item
	  * @details provides inter-object communication via signals and slots.
	  */
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
	
protected:
	/**
	  * @brief Animates the food moving around the screen
	  * @details
	  */
	QPropertyAnimation* moveAnimation = nullptr;
	
public:
	/**
	 * @brief Food default constructor
	 */
	Food();
	
	/**
	  * @brief Food default destructor
	  */
	~Food();
	
	/**
	 * @brief setInitialPos Set the initial position of this item
	 * @details it chose a random initial position for the X axis within the screen, the y axis keeps always on 0
	 */
	virtual void setInitialPos();
	
	virtual void reactTo();
};


class Ex : public FallingObject
{
	Q_OBJECT
	Q_DISABLE_COPY(Ex)
	
	/**
	  * @brief Create a position property to animate the movement of this item
	  * @details provides inter-object communication via signals and slots.
	  */
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
	
protected:
	/**
	  * @brief Animates the food moving around the screen
	  * @details
	  */
	QPropertyAnimation* moveAnimation = nullptr;
	
public:
	/**
	 * @brief Food default constructor
	 */
	Ex();
	
	/**
	  * @brief Food default destructor
	  */
	~Ex();
	
	/**
	 * @brief setInitialPos Set the initial position of this item
	 * @details it chose a random initial position for the X axis within the screen, the y axis keeps always on 0
	 */
	virtual void setInitialPos();
	
	virtual void reactTo();
};
#endif // FOOD_H
