#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSvgRenderer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSoundEffect>
#include <QTime>
#include <QTimer>

#include "Snek.h"
#include "Game.h"
#include "Snek.h"
Game::Game(int &argc, char **argv, int flags)
	: QApplication(argc, argv, flags)
{
}

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

    // Load the graphic resources
    this->svgRenderer = new QSvgRenderer(QString("://assets.svg"), this);

    // Create the player control
    Snek* snek = new Snek();
    //this->snek = new Snek();
    snek->setSharedRenderer(svgRenderer);
    scene->addItem(snek);
    snek->setInitialPos();

    // Show the view and enter in application's event loop
    this->view->show();
    return exec();
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
	
	// Show the view and enter in application's event loop
	this->view->show();
	return exec();
}
