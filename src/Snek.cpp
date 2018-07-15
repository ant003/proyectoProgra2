#include "Snek.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPropertyAnimation>
#include <QTimer>
#include <QSoundEffect>
#include <QtMath>

const int monsterDelay = 150; // milliseconds

Snek::Snek()
{
	// Set graphic image
<<<<<<< HEAD
    setElementId( QString("snek"));
=======
	setElementId("snek");
>>>>>>> 14de76848a8ef6819695b3e42d5484ab3ca5c411
//	setFlags(QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);

	// Pre-load the collision sound SONIDO DE LA SNEK COMIENDO
	collisionSound = new QSoundEffect(qApp);
	collisionSound->setSource(QUrl("qrc:/Stop.wav"));
	collisionSound->setVolume(0.98f);

//	// Continuously check for collisions
//	QTimer* collisionTimer = new QTimer(this);
//	connect(collisionTimer, &QTimer::timeout, this, &Snek::detectCollisions);
//	collisionTimer->setInterval(25);
//	collisionTimer->start();
}

Snek::~Snek()
{
}

void Snek::setInitialPos()
{
	// Place the Snek in the middle bottom of the scene
	this-> x = (scene()->width() - boundingRect().width()) * 0.5;
	this-> y = (scene()->height() - boundingRect().height()) * 0.5;
	setPos(x, y);
}

void Snek::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	this->x = event->lastPos().x();
	setPos(this->x,this->y);
}
