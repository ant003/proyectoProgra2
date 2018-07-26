#include "ExitButton.h"
#include <iostream>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QPropertyAnimation>
#include <QTimer>
#include <QSoundEffect>
#include <QtMath>
#include <Score.h>

ExitButton::ExitButton()
{
    // Set graphic image
    setElementId("icon");
    setFlag(QGraphicsItem::ItemIsFocusable);
    setScale(2);
    setFocus();
}

void ExitButton::setInitialPos()
{
    qreal x = (scene()->width()/2 - boundingRect().width());
    qreal y = (scene()->height()/2 - boundingRect().height());;
    setPos(x, y);
}

void ExitButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    event = event;
    emit clicked();
}


