#ifndef FALLINGOBJECT_H
#define FALLINGOBJECT_H

#include "AnimatedObject.h"

class QPropertyAnimation;

class FallingObject : public AnimatedObject
{
	Q_OBJECT
	Q_DISABLE_COPY(FallingObject)
	/**
	*@brief Create a position property to animate the movement of this item
	*@details provides inter-object communication via signals and slots.
	*/
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
protected:
	/**
	* @brief Animates the food moving around the screen
	* @details
	*/
	QPropertyAnimation* moveAnimation = nullptr;
	bool touched;
	double speed;
	int value;
	
public:
	FallingObject( const char* name );
	virtual ~FallingObject();
	/**
	 * @brief setInitialPos Set the initial position of this item
	 * @details it chose a random initial position for the X axis within the screen, the y axis keeps always on 0
	 */
	virtual void setInitialPos() = 0;
	
	virtual void reactTo() = 0;
	
	virtual bool getStatus() const;
	
	virtual void setSpeed( double speed );
	
	virtual int getValue() const;
	
	virtual void setValue(int value);

public slots:
	/**
	 * @brief move food move the food down
	 * @details stablish the movement of the food trough the screen, if hits a snek graphic item it gets remove from scene
	 */
	virtual void move();
	
};

#endif // FALLINGOBJECT_H
