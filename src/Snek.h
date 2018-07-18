#ifndef SNEK_H
#define SNEK_H
#include "AnimatedObject.h"

class QPropertyAnimation;
class QSoundEffect;
class QMouseEvent;
class Score;
class QKeyEvent;
class Snek : public AnimatedObject
{
public:
	Q_OBJECT
	Q_DISABLE_COPY(Snek)
	
	/// Create a position property to animate the movement of this item
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
	
protected:
	/// To generate sounds when the player is activated
	QSoundEffect* collisionSound = nullptr;
	/// Animates the monster moving around the screen
	QPropertyAnimation* moveAnimation = nullptr;
	
public:
	bool movementRight;
	bool movementLeft;
	Score* score;
	/**
	*@param Score* score
	*@brief Constructor of the object that creates it and also communicates itself with the score
	*@details Because this item know when to detect any collition, it can update the score with ease, so the scene will delegate this
	*/
	Snek(Score* score);
	/// Destructor
	~Snek();
	/// Centers the player in the center bottom of the scene
	void setInitialPos();
	/// Move to left
	void moveLeft();
	/// Move to right
	void moveRight();

protected:
    virtual void keyPressEvent(QKeyEvent *event) override;

    virtual void keyReleaseEvent(QKeyEvent *event) override;
	
protected slots:
	/**
	*@brief checks if either movementRight or movementLeft is at high
	*@details at a given timer will check if any of the movement booleans is active and if so will move the item in the given direction
	*/
	void detectMovement();
	/**
	*@brief checks if there's an object colliding with it 
	*@details at a given timer will check if there's an item colliding with it and if so, generates a list with each one of the items colliding an manages each case to react
	*/
	void detectCollisions();
	/**
	*@brief if it's given a clicked signal, will change the according movement boolean to true
	*/
	void setToRight();
	/**
	*@brief if it's given a clicked signal, will change the according movement boolean to true
	*/
	void setToLeft();
	/**
	*@brief if it's given a released signal, will change the according movement boolean to false
	*/
	void setToLeftStop();
	/**
	*@brief if it's given a released signal, will change the according movement boolean to false
	*/
	void setToRightStop();
};

#endif // Snek_H
