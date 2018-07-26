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

    /// Manages graphic items. It is an invisible manager
	QGraphicsScene* scene;


    ///  A visible widget that renders the scene
	QGraphicsView* view;


    /// A resource that contains a set of sprites that will be used in game
	QSvgRenderer* svgRenderer = nullptr;


    ///A graphic item that will be controlled by the player
	Snek* snek;


    /// A Qlabel item that will display the score achieved by the player
	Score* score;
	

     /// A Qlabel item that will display the highscore achieved by the player
	Score* highScoreMarker;


     ///foodSpawn a pointer to the food timer
    QTimer* foodSpawn;


     /// obstacleSpawn a pointer to the obstacleSpawn
    QTimer* obstacleSpawn;


     /// exitButtonCreated lets to check if the exit button was already created
    bool exitButtonCreated;

	int highScore;
	
    int speed;

    /// instantiates and positionates the snek
	void setSnek();
	
    /// searches the highSCore within in the Qsettings
	void loadHighScore();
	
    /// stores the highScore in the Qsettings
	void storeHighScore();


public:
    static int const rebootCode = 666;
	/// Constructor
	Game(int &argc, char **argv, int flags = ApplicationFlags);
	/// Destructor
	~Game();
	/// Call this method instead of exec()
	int run();
	
	//    /// Play the given filename as background music
	//      void playBackgroundMusic(const QString& audioFilename);
	
protected slots:

    /// slot method that is called each time a new food item must be spawned
	void launchFood();
	
    /// slot method that is called to check if the player lose all health
    void endGame();
	
    /// slot method that is called each 2 seconds to update speed
    void updateSpeed();

    /// slot method that is called each 2 seconds to launch an obstacle
	void launchObstables();

    /// slot method called when a reboot is requested
    void reboot();
};

#endif // GAME_H
