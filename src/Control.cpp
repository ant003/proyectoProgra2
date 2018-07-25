#include "Control.h"

Control::Control()
{
}

void Control::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	event = event;
    emit clicked();
}

void Control::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	event = event;
    emit released();
}

MouseScreen::MouseScreen()
{
	// instantiates the left and right pad and makes it so they cant handle all the events
	leftPad = new Control();
	leftPad->setFlag(QGraphicsItem::ItemStopsFocusHandling);
	rightPad = new Control();
	rightPad->setFlag(QGraphicsItem::ItemStopsFocusHandling);
}

void MouseScreen::setPads(QGraphicsScene* scene)
{
	// adds the pads to the scene
	scene->addItem(rightPad);
	scene->addItem(leftPad);
	
	// paints the left pad and positionates it within the scene
	leftPad->setRect(0,0,scene->width()/2,scene->height());
	leftPad->setBrush(QBrush(qRgb(111, 157, 232),Qt::SolidPattern));
	leftPad->setPen(Qt::NoPen);
	
	// paints the right pad and positionates it within the scene
	rightPad->setRect(scene->width()/2,0,scene->width()/2,scene->height());
	rightPad->setBrush(QBrush(qRgb(111, 157, 232),Qt::SolidPattern));
	rightPad->setPen(Qt::NoPen);
}
