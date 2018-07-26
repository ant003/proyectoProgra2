#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSvgRenderer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSoundEffect>
#include <QTime>
#include <QTimer>
#include <QColor>
#include <QSettings>

#include "Snek.h"
#include "Game.h"
#include "Snek.h"
#include "Control.h"
#include "Food.h"
#include "Score.h"
#include "Gate.h"

#include <QDebug>

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
	
	loadHighScore();
	
	
	// A label to show the player score
	this->score = new Score(tr("Lives"), 0, 0, Qt::white);
	this->score->setPos(5, 0);
	this->scene->addItem(this->score);
	this->score->setZValue(qreal(200));
	
	// A label to show the player the highest score achieved
	this->highScoreMarker = new Score(tr("Highscore"), 0 , this->highScore, Qt::white);
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
	
	// Launch a food periodically
	QTimer* foodSpawn = new QTimer(this);
	connect(foodSpawn, &QTimer::timeout, this, &Game::launchFood);
	foodSpawn->start(1000);
	
	// Launch food periodically
	QTimer* obstacleSpawn = new QTimer(this);
	connect(obstacleSpawn,&QTimer::timeout, this, &Game::launchObstables);
	obstacleSpawn->start(10000);
	
	// Check if the game reached end condition or if the speed needs an update
	QTimer* checkEnd = new QTimer(this);
	connect(checkEnd, &QTimer::timeout, this, &Game::endGame);
	connect( checkEnd, &QTimer::timeout, this, &Game::updateSpeed);
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

void Game::launchObstables()
{
	Gate* obstacle1;
	Gate* obstacle2;
	Gate* obstacle3;
	Gate* obstacle4;
	obstacle1 = new Gate("Number2");
	obstacle2 = new Gate("RomanVII");
	obstacle3 = new Gate("CharA");
	obstacle4 = new Gate("RomanXI");
	obstacle1->setSharedRenderer(svgRenderer);
	obstacle2->setSharedRenderer(svgRenderer);
	obstacle3->setSharedRenderer(svgRenderer);
	obstacle4->setSharedRenderer(svgRenderer);
	scene->addItem(obstacle1);
	scene->addItem(obstacle2);
	scene->addItem(obstacle3);
	scene->addItem(obstacle4);
	obstacle1->setInitialPos(0);
	obstacle2->setInitialPos(1);
	obstacle3->setInitialPos(2);
	obstacle4->setInitialPos(3);
}

void Game::setSnek()
{
	scene->addItem(snek);
	this->snek->setInitialPos();
	this->snek->setZValue(qreal(200));
	this->snek->setFocus();
}
#include <iostream>
void Game::storeHighScore()
{
	QSettings settings("MyGame","MyScore");
	settings.beginGroup("Scores");
	settings.setValue("HighScore",this->highScore);
	settings.endGroup();
	std::cout << "stored:" << this->highScore << std::endl;
}

void Game::loadHighScore()
{
	QSettings settings("MyGame","MyScore");
	settings.beginGroup("Scores");
	int value = settings.value("HighScore",0).toInt();
	this->highScore = value;
	settings.endGroup();
	std::cout << "loaded:" << this->highScore << std::endl ;
}

void Game::endGame()
{
	if(this->score->getLives() < 0)
	{
		if( this->score->getScore() > this->highScore )
		{
			this->highScore = this->score->getScore();
			storeHighScore();
		}
	this->exit();
	}
}
void Game::updateSpeed()
{
	FallingObject* object;
	int newSpeed = this->score->getLives() > 5 ? this->score->getLives()/5 : 1;
	const QList<QGraphicsItem*>& items = this->scene->items();
	for ( QGraphicsItem* item : items )
	{
		// ranas duran 2.5 s en caer y 1.5 en salir
		// velocidad, si aumenta en 5 el alimento que tiene incremente un 0.2
		// If a graphic item is a graphic object react to it
		if ( (object = dynamic_cast<FallingObject*>(item)) )
		{
			object->setSpeed(newSpeed);//a determinar
		}
	}
}
