#ifndef EXITBUTTON_H
#define EXITBUTTON_H
#include "AnimatedObject.h"
class QPropertyAnimation;
class QSoundEffect;
class QMouseEvent;
class Score;
class QKeyEvent;


class ExitButton : public AnimatedObject
{

    Q_OBJECT
    Q_DISABLE_COPY(ExitButton)

    /// Create a position property to animate the movement of this item
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)

public:

    ExitButton();

    void setInitialPos();

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
signals:
    void clicked();
};



#endif // EXITBUTTON_H
