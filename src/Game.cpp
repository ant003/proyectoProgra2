#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSvgRenderer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSoundEffect>
#include <QTime>
#include <QTimer>
#include <QColor>
//#include <QString>
#include <QSettings>

#include "Snek.h"
#include "Game.h"
#include "Snek.h"
#include "Control.h"
#include "Food.h"
#include "Score.h"

Game::Game(int &argc, char **argv, int flags) : QApplication(argc, argv, flags) {}

Game::~Game()
{
	delete this->scene;
	delete this->view;
}

int Game::run()
{
	
	// Init the random seed
	qsrand(QTime::currentTime().msec());
	// An invisible object that manages all the items
	this->scene = new QGraphicsScene();
	// A visible rectangle of the scene
	this->view = new QGraphicsView(this->scene);
#if ! defined(Q_OS_ANDROID) && ! defined(Q_OS_IOS)
	this->view->resize(800, 600);
	this->view->setFixedSize(800,600);
	this->view->setMouseTracking(true);
#endif
	
	// Set a black color background or add an image as a background
	this->view->setBackgroundBrush(QBrush(Qt::blue, Qt::SolidPattern));
	// The scene has infinite size, but we want it has the same size than the view
	// This stops the weird behavior of the autoscroll feature of the view being smaller than the
	// scene, because the scene auto-increases when objects are moved
	this->scene->setSceneRect( this->view->rect() );
	
	// Disable scrollbars because they are not longer needed
	this->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	
	this->highScore = loadHighScore();
	
	
	// A label to show the player score
	this->score = new Score(tr("Lives"), 0, 0, Qt::black);
	this->score->setPos(5, 0);
	this->scene->addItem(this->score);
	this->score->setZValue(qreal(200));
	// A label to show the player the highest score achieved
	this->highScoreMarker = new Score(tr("Highscore"), this->highScore ,0, Qt::black);
	highScoreMarker->setPos(this->scene->width()-200,0);
	this->scene->addItem(highScoreMarker);
	highScoreMarker->setZValue(200);
	
	// Load the graphic resources
	this->svgRenderer = new QSvgRenderer(QString("://assets.svg"), this);
	
	//Sets the window tittle
	this->view->setWindowTitle("Snek");
	
	// Create the snake and pass the score control to it
	this->snek = new Snek(score);
	this->snek->setSharedRenderer(svgRenderer);
	setSnek();
	
	// Set controls
	MouseScreen control = MouseScreen();
	control.setPads(this->scene);
	connect ( control.rightPad, SIGNAL(clicked()), snek, SLOT(setToRight()) );
	connect ( control.rightPad, SIGNAL(released()), snek, SLOT(setToRightStop()) );
	connect ( control.leftPad, SIGNAL(clicked()), snek, SLOT(setToLeft()) );
	connect ( control.leftPad, SIGNAL(released()), snek, SLOT(setToLeftStop()) );
	
	// Launch an food periodically
	QTimer* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &Game::launchFood);
	timer->start(1500);
	
	QTimer* checkEnd = new QTimer(this);
	connect(checkEnd, &QTimer::timeout, this, &Game::endGame);
	checkEnd->start(50);
	
	// Show the view and enter in application's event loop
	this->view->show();
	return exec();
}

void Game::launchFood()
{
	Food* food = new Food();
	food->setSharedRenderer(svgRenderer);
	scene->addItem(food);
	food->setInitialPos();
}

void Game::setSnek()
{
	scene->addItem(snek);
	this->snek->setInitialPos();
	this->snek->setZValue(qreal(200));
	this->snek->setFocus();
}

void Game::storeHighScore()
{
	QSettings settings;
	settings.beginGroup(QString("scores"));
	settings.setValue(QString("key"), highScore);
	settings.endGroup();
}

int Game::loadHighScore()
{
	QSettings settings;
	settings.beginGroup(QString("scores"));
	int value = settings.value(QString("key"), 0 ).toInt();
	settings.endGroup();
	return value;
}

void Game::endGame()
{
	if(this->score->getLives() == 0)
	{
		if( this->score->getScore() > this->highScore )
		{
			this->highScore = this->score->getScore();
			storeHighScore();
		}
	}
}
