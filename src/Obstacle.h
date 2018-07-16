#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <QGraphicsSvgItem>

class Obstacle : public QGraphicsSvgItem
{
    Q_OBJECT
    Q_DISABLE_COPY(Obstacle)

  public:
    /// Constructor
    explicit Obstacle(QGraphicsItem* parent = nullptr);
    /// Set the initial position of this item
    virtual void setInitialPos();
};

#endif // OBSTACLE_H
