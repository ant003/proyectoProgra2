#include <QColor>
#include <QFont>

#include "Score.h"

Score::Score(const QString& legend, int initialScore,int lives,QColor color, QGraphicsItem* parent)
	: QGraphicsTextItem(parent)
	, legend(legend)
	, score(initialScore)
	, lives(lives)
{
	setDefaultTextColor(color);
	setFont(QFont("", 24));
	updateScore();
}

Score::~Score()
{
}

void Score::increase(int amount)
{
	// changes the score and calls for the update
	if( amount > 0 )
		score += amount,
		lives += amount;
	else
		lives = lives-amount ? lives-amount : 0;
	updateScore();
}

void Score::updateScore()
{
	// changes the text displayed in the Qlabel
	setPlainText( QString("%1: %2").arg(legend).arg(lives) );
}
