#ifndef FOOD_H
#define FOOD_H
#include "AnimatedObject.h"

class QPropertyAnimation;

class Food : public AnimatedObject
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
	bool touched;
	
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
	void setInitialPos();
	
	bool getStatus() const;
	
	void setStatus(bool status);
	
public slots:
	/**
	 * @brief move food move the food down
	 * @details stablish the movement of the food trough the screen, if hits a snek graphic item it gets remove from scene
	 */
	void move();
	
};

#endif // FOOD_H
