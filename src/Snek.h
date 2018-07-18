#ifndef SNEK_H
#define SNEK_H
#include "AnimatedObject.h"

class QPropertyAnimation;
class QSoundEffect;
class QMouseEvent;

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
	/// Constructor
	Snek();
	/// Destructor
	~Snek();
	/// Centers the player in the center bottom of the scene
	void setInitialPos();
    /// Move to left
    void moveLeft();
    /// Move to right
    void moveRight();

protected slots:
    /// Will check if any movement was requested
    void detectMovement();

    void setToRight();

    void setToLeft();

    void setToLeftStop();

    void setToRightStop();
};

#endif // Snek_H
