#include "Game.h"

int main(int argc, char *argv[])
{
	// Represents the whole application

    int currenExitCode = 0;
    do{
        Game game(argc, argv);
        currenExitCode = game.run();
    }while(currenExitCode == Game::rebootCode);

    return currenExitCode;
}
