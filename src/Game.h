#ifndef GAME_H
#define GAME_H

#include <QApplication>
class Snek;
class QGraphicsScene;
class QSvgRenderer;
class QGraphicsView;
class Score;

class Game : public QApplication
{
	Q_DISABLE_COPY(Game)
protected:
	/**
	*@brief Manages graphic items. It is an invisible manager
	*@details The scene is the owner of all the items in it and must be rendered by other object
	*/
	QGraphicsScene* scene;
	/**
	*@brief  A visible widget that renders the scene
	*@details The view renders the scene and will show a limited part of the scene
	*/
	QGraphicsView* view;
	/**
	*@brief A resource that contains a set of sprites that will be used in game
	*@details The svgRenderer will be used to assign each graphic item defined a representation
	*/
	QSvgRenderer* svgRenderer = nullptr;
	/**
	*@brief A graphic item that will be controlled by the player
	*@details this graphic item will be controlled by two in-screen pads and has the capabilities to detect events about itself like collisions or updates in the movement controls
	*/
	Snek* snek;
	/**
	*@brief A Qlabel item that will display the score achieved by the player
	*@details Must be connected to the snek so it can control the score since the collision detection is inside the snek
	*/
	Score* score;
	
	void setSnek();
	
public:
	/// Constructor
	Game(int &argc, char **argv, int flags = ApplicationFlags);
	/// Destructor
	~Game();
	/// Call this method instead of exec()
	int run();
	
	//    /// Play the given filename as background music
	//      void playBackgroundMusic(const QString& audioFilename);
	
protected slots:
	/**
	*@brief slot method that is called each time a new food item must be spawned
	*@details food is spawned according to an internal timer in the game class
	*/
	void launchFood();
    void updateSize();
	
};

#endif // GAME_H
