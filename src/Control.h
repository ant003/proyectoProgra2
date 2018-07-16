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
signals:
//    void clicked(QGraphicsSceneMouseEvent *event);
        void clicked();
};

#endif // CONTROL_H
