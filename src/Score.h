#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

/**
 * @brief A game label on the screen that shows a legend and a counter value
 * For example: to show the player's score, lifes, remaining time
 */
class Score : public QGraphicsTextItem
{
	Q_OBJECT
	Q_DISABLE_COPY(Score)
	
protected:
	/// This scores measures something: health, power, bonus, points...
	QString legend;
	/// The amount scored
	int score;
	
public:
    /**
     * @brief Score a constructor for a new score
     * @param legend the name of the new score, like a label
     * @param initialScore the number to inicialize the new score
     * @param color the color of the new score label
     * @param parent the inherit parent
     */
	Score(const QString& legend, int initialScore, QColor color, QGraphicsItem *parent = nullptr);

    /**
      * @brief the default destructor
      */
	~Score();
    /**
     * @brief getScore Returns a copy of the current score
     * @return the current score
     */
	inline int getScore() const { return score; }

    /**
     * @brief increase increase the score and updates the view
     * @param amount the amount to increase the score
     */
	void increase(int amount = 1);


    /**
     * @brief decrease Decreases the score and updates the view
     * @param amount the amount to decrease the score
     */
	void decrease(int amount = 1);
	
protected:
    /**
     * @brief updateScore Updates the interface to match the int attribute score
     */
	void updateScore();
};

#endif // SCORE_H
