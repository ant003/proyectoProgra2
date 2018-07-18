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
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
signals:
	//    void clicked(QGraphicsSceneMouseEvent *event);
	void clicked();
	void released();
};

#endif // CONTROL_H
