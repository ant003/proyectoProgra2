#ifndef ANIMATEDOBJECT_H
#define ANIMATEDOBJECT_H

#include <QGraphicsSvgItem>

class QTimer;

/**
 * @brief An item that moves within the screen
 */
class AnimatedObject : public QGraphicsSvgItem
{
	Q_OBJECT
	Q_DISABLE_COPY(AnimatedObject)
	
protected:
	/// To produce the move-up animation
	QTimer* timer;
	
public:
    /**
     * @brief AnimatedObject
     * @param parent
     */
	explicit AnimatedObject(QGraphicsItem* parent = nullptr);

    /**
      * @brief the default constructor
      */
	~AnimatedObject();

    /**
     * @brief destroy Stops the timer, removes this object from the scene, and destroys it
     * @param removeFromScene sets if the object needs to be removed
     * @param deleteObject sets if the object needs to be deleted
     */
	void destroy(bool removeFromScene = true, bool deleteObject = true);
};

#endif // ANIMATEDOBJECT_H
