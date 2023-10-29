#include <iostream>
#include "game.hpp"


int main(int argc, char* argv[])
{

	Game game;

	const int FPS = 60;

	game.render();

	while (game.running())
	{
		game.handleEvents();
		game.update();
		game.render();
	}

	return 0;
}