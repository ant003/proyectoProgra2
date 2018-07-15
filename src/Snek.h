#ifndef SNEK_H
#define SNEK_H
#include "AnimatedObject.h"

class QPropertyAnimation;
class QSoundEffect;



class Snek
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
	/// Constructor
	Snek();
	/// Destructor
	~Snek();
	/// Centers the player in the center bottom of the scene
	void setInitialPos();
	/// Called when this item is clicked or tapped by the user
	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;

  protected slots:
	/// Move the player around the scene
	void move();
	/// Detect and react to collisions with other elements
	void detectCollisions();
};

#endif // Snek_H