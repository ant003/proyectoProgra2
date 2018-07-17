#ifndef FOOD_H
#define FOOD_H
#include <QGraphicsSvgItem>
#include <QObject>

class Food : public QGraphicsSvgItem
{
    Q_OBJECT
    Q_DISABLE_COPY(Food)

  public:
    /// Constructor
    explicit Food(QGraphicsItem* parent = nullptr);
    /// Set the initial position of this item
    void setInitialPos();
    /// Called when this item is clicked or tapped by the user
    //virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
   public slots:
    void move();

};

#endif // FOOD_H
