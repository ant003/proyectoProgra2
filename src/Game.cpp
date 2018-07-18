#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSvgRenderer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSoundEffect>
#include <QTime>
#include <QTimer>
#include <QColor>

#include "Snek.h"
#include "Game.h"
#include "Snek.h"
#include "Control.h"
#include "Food.h"
#include "Score.h"

Game::Game(int &argc, char **argv, int flags)
	: QApplication(argc, argv, flags)
{
	
}

Game::~Game()
{
	delete this->scene;
	delete this->view;
	delete this->score;
	delete this->snek;
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
	this->view->setMouseTracking(true);
#endif
	
	// Set a black color background or add an image as a background
	this->view->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
	// The scene has infinite size, but we want it has the same size than the view
	// This stops the weird behavior of the autoscroll feature of the view being smaller than the
	// scene, because the scene auto-increases when objects are moved
	this->scene->setSceneRect( this->view->rect() );
	
	// Disable scrollbars because they are not longer needed
	this->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	
	// A label to show the player score
	this->score = new Score(tr("Score"), 0, Qt::black);
	this->score->setPos(5, 0);
	this->scene->addItem(this->score);
	this->score->setZValue(qreal(200));
	
	// Load the graphic resources
	this->svgRenderer = new QSvgRenderer(QString("://assets.svg"), this);
	
	// Create the snake and pass the score control to it
	Snek* snek = new Snek(score);
	snek->setSharedRenderer(svgRenderer);
	scene->addItem(snek);
	snek->setInitialPos();
	snek->setZValue(qreal(200));
	
	// Create the controls of the player
	Control* leftControl = new Control();
	leftControl->setRect(0,0,this->scene->width()/2,this->scene->height());
	leftControl->setBrush(QBrush(qRgb(111, 157, 232),Qt::SolidPattern));
	this->scene->addItem(leftControl);
	connect ( leftControl, SIGNAL(clicked()), snek, SLOT(setToLeft()) );
	connect ( leftControl, SIGNAL(released()), snek, SLOT(setToLeftStop()) );
	
	Control* rightControl = new Control();
	rightControl->setRect(this->scene->width()/2,0,this->scene->width()/2,this->scene->height());
	rightControl->setBrush(QBrush(qRgb(216, 117, 106),Qt::SolidPattern));
	this->scene->addItem(rightControl);
	connect ( rightControl, SIGNAL(clicked()), snek, SLOT(setToRight()) );
	connect ( rightControl, SIGNAL(released()), snek, SLOT(setToRightStop()) );
	
	// Launch an food periodically
	QTimer* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &Game::launchFood);
	timer->start(1500);
	
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

