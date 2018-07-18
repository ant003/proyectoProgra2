#ifndef CONTROL_H
#define CONTROL_H
#include <QGraphicsRectItem>
#include <QObject>
class Control : public QObject, public QGraphicsRectItem
{
	Q_OBJECT
public:
	Control();
	
protected:
	/**
	*@brief Action meant to be only when this item is clicked by the player
	*@details emits the clicked signal
	*/
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
	/**
	*@brief Action meant to be only when this item was being clicked and the player releases the button
	*@details emits the released signal
	*/
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
signals:
	void clicked();
	void released();
};

#endif // CONTROL_H
