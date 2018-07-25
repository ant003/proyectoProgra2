#ifndef CONTROL_H
#define CONTROL_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsScene>
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

class MouseScreen
{
public:
	MouseScreen();
	Control* leftPad;
	Control* rightPad;
	/**
	 * @brief setPads Acomodates the left and the right pads to the scene in which they'll be displayed
	 * @param scene
	 */
	
	void setPads(QGraphicsScene* scene);
};

#endif // CONTROL_H
