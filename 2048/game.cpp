#include <iostream>
#include "game.hpp"

Game::Game() {}

Game::~Game() {}

void Game::handleEvents() {

}

void Game::update() {
	bool isMoving = true;
	while (isMoving) {
		int i;
		int y;
		for (i; i < 4; i++) {
			for (y; y < 3; y++) {
				if (grid[i][y + 1] == 0) {
					grid[i][y + 1] = grid[i][y];
					grid[i][y] = 0;
				} else if (grid[i][y + 1] == grid[i][y + 1]) {
					grid[i][y + 1] = grid[i][y]^2;
					grid[i][y] = 0;
				}
			}
		}
	}
}

void Game::render() {

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << grid[i][j] << ' ';
		}
		std::cout << "\n";
	}
}