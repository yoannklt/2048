#include <iostream>
#include "game.hpp"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	game = new Game();

	const int FPS = 60;

	game->init();

	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clear();

	return 0;
}