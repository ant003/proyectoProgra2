#include "Snek.h"
#include <iostream>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPropertyAnimation>
#include <QTimer>
#include <QSoundEffect>
#include <QtMath>

Snek::Snek()
    :movementRight{false}
    ,movementLeft{false}
{
	// Set graphic image
    setElementId( QString("snek"));
	setElementId("snek");
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


    // Continuously check for collisions
    QTimer* collisionTimer = new QTimer(this);
    connect(collisionTimer, &QTimer::timeout, this, &Snek::detectMovement());
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
    setPos(x, this->pos().y() );
}

void Snek::moveRight()
{
    qreal x = this->pos().x()+10;
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
