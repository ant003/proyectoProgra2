#include "Control.h"

Control::Control()
{
	
}

void  Control::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	event = event;
    emit clicked();
}

void Control::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	event = event;
    emit released();
}

