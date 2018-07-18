#include "Control.h"

Control::Control()
{
	
}

void  Control::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	emit clicked();
}

void Control::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	emit released();
}

//void  Control::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    emit clicked(event);
//}
