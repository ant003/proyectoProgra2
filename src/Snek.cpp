#include "Snek.h"
#include <iostream>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QPropertyAnimation>
#include <QTimer>
#include <QSoundEffect>
#include <QtMath>
#include <Score.h>
Snek::Snek(Score* score)
	:movementRight{false}
	,movementLeft{false}
	,score{score}
{
	// Set graphic image
	setElementId( QString("snek"));
	setElementId("snek");
	setFlag(QGraphicsItem::ItemIsFocusable);
	setFocus();
	
	// Pre-load the collision sound SONIDO DE LA SNEK COMIENDO
	//	collisionSound = new QSoundEffect(qApp);
	//	collisionSound->setSource(QUrl("qrc:/Stop.wav"));
	//	collisionSound->setVolume(0.98f);
	
	// Continuously check for collisions
	QTimer* collisionTimer = new QTimer(this);
	connect(collisionTimer, &QTimer::timeout, this, &Snek::detectMovement);
	connect(collisionTimer, &QTimer::timeout, this, &Snek::detectCollisions);
	collisionTimer->setInterval(25);
	collisionTimer->start();
	
}

Snek::~Snek()
{
}

void Snek::setInitialPos()
{
	// Place the Snek in the middle bottom of the scene
	qreal x = (scene()->width() - boundingRect().width()) * 0.5;
	qreal y =scene()->height() - scene()->height()/3;
	setPos(x, y);
}

void Snek::detectMovement()
{
	if(movementLeft)
		this->moveLeft();
	if(movementRight)
		this->moveRight();
}

void Snek::moveLeft()
{
	qreal x = this->pos().x()-10;
	if(0<=x)
		setPos(x, this->pos().y() );
}

void Snek::moveRight()
{
	qreal x = this->pos().x()+10;
	if(x<= scene()->width() - this->boundingRect().width() )
		setPos(x, this->pos().y() );
}

void Snek::setToRight()
{
	this->movementRight = true;
}
void Snek::setToLeft()
{
	this->movementLeft = true;
}

void Snek::setToRightStop()
{
	this->movementRight = false;
}
void Snek::setToLeftStop()
{
	this->movementLeft = false;
}

#include "Food.h"
void Snek::detectCollisions()
{
	// Traverse all graphic items that are colliding with this
	Food* foodCollided;
	const QList<QGraphicsItem*>& items = collidingItems();
	for ( QGraphicsItem* item : items )
	{
		// If a graphic item is an obstacle remove it from scene
		if ( (foodCollided = dynamic_cast<Food*>(item)) )
		{
			// Play the collision sound
			//			this->collisionSound->play();
			if( foodCollided->getStatus() == false)
			this->score->increase();
		}
	}
}
#include <iostream>
void Snek::keyPressEvent(QKeyEvent *event)
{
	static_cast<void>(event);
	std::cout << event->key();
	if(event->key() == Qt::Key_Left)
		this->setToLeft();
	else if(event->key() == Qt::Key_Right)
		this->setToRight();
}

void Snek::keyReleaseEvent(QKeyEvent *event)
{
	static_cast<void>(event);
	if(event->key() == Qt::Key_Left)
		this->setToLeftStop();
	else if(event->key() == Qt::Key_Right)
		this->setToRightStop();
}
