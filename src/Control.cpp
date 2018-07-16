#include "Control.h"

Control::Control()
{

}

void  Control::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}



//void  Control::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    emit clicked(event);
//}
