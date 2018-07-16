#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "Obstacle.h"

Obstacle::Obstacle(QGraphicsItem* parent)
    : QGraphicsSvgItem(parent)
{
}

virtual void Obstacle::setInitialPos() const = 0;
