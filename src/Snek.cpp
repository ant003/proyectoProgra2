#include "Snek.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPropertyAnimation>
#include <QTimer>
#include <QSoundEffect>
#include <QtMath>

const int monsterDelay = 150; // milliseconds

snek::snek()
{
	// Set graphic image
	setElementId( QString("monster%1").arg( qrand() % 3 ) );
//	setFlags(QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);

	// Pre-load the collision sound SONIDO DE LA SNEK COMIENDO
	collisionSound = new QSoundEffect(qApp);
	collisionSound->setSource(QUrl("qrc:/Stop.wav"));
	collisionSound->setVolume(0.98f);

	// Continuously check for collisions
	QTimer* collisionTimer = new QTimer(this);
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
	qreal y = (scene()->height() - boundingRect().height()) * 0.5;
	setPos(x, y);
}

virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override
{
	setPos(event->x(),(scene()->height() - boundingRect().height()) * 0.5);
}
/*
#include "Obstacle.h"
void Snek::detectCollisions()
{
	// Traverse all graphic items that are colliding with this
	const QList<QGraphicsItem*>& items = collidingItems();
	for ( QGraphicsItem* item : items )
	{
		// If a graphic item is an obstacle remove it from scene
        if ( /*Obstacle* obstacle =*/ /*dynamic_cast<Obstacle*>(item) )
		{
			// Play the collision sound
			this->collisionSound->play();

			// Stop current move animation and move in another direction
			this->moveAnimation->stop();
			this->move();
		}
	}

}
