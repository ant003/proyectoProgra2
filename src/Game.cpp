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
#include "ExitButton.h"
#include <QDebug>



Game::Game(int &argc, char **argv, int flags) : QApplication(argc, argv, flags) {}
// Default constructor
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
    this->view->setBackgroundBrush(QBrush(qRgb(111, 157, 232),Qt::SolidPattern));
	// The scene has infinite size, but we want it has the same size than the view
	// This stops the weird behavior of the autoscroll feature of the view being smaller than the
	// scene, because the scene auto-increases when objects are moved
	this->scene->setSceneRect( this->view->rect() );
	
	// Disable scrollbars because they are not longer needed
	this->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	
    loadHighScore();
    exitButtonCreated = false;
	
	// A label to show the player score
    this->score = new Score(tr("Health"), 0, 0, Qt::white);
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
    foodSpawn = new QTimer(this);
	connect(foodSpawn, &QTimer::timeout, this, &Game::launchFood);
	foodSpawn->start(1000);
	
	// Launch food periodically
    obstacleSpawn = new QTimer(this);
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

// Defines the launch of a new food(frogs)
void Game::launchFood()
{
	Food* food = new Food();
	food->setSharedRenderer(svgRenderer);
	scene->addItem(food);
	food->setInitialPos();
}

// Defines the launch of a new obstacle(door)
void Game::launchObstables()
{
	GateManager* manager = new GateManager();
	manager->setUpSharedRenderer(this->svgRenderer);
    manager->addToScene(this->scene);
}

// Executes the reboot of the game
void Game::reboot()
{
    this->exit(rebootCode);
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

// Get the actual healt to update the highscore and wait for the signal to reboot
void Game::endGame()
{
    if(this->score->getLives() < 0 && ! exitButtonCreated)
	{
		if( this->score->getScore() > this->highScore )
		{
            this->highScore = this->score->getScore();
            //this->highScore = 0;
            // Set the exit button
			storeHighScore();
		}
        ExitButton* button = new ExitButton();
            connect(button, &ExitButton::clicked, this, &Game::reboot);
        //connect(button, SIGNAL(clicked()),this,SLOT(reboot()));
        foodSpawn->stop();
        obstacleSpawn->stop();
        this->scene->clear();
        this->scene->addItem(button);
        button->setSharedRenderer(svgRenderer);
        button->setInitialPos();
        // set initial pos

        this->exitButtonCreated = true;
	}
}

//Sets the new new speed acoording to the time passed
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

