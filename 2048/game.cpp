#include <iostream>
#include "game.hpp"

Game::Game() {}

Game::~Game() {}

void Game::handleEvents() {

}

void Game::update() {
	bool isMoving = true;
	int i, y, iAdd, yAdd = 0;
	while (isMoving) {
		iAdd = directionVect[0];
		yAdd = directionVect[1];

		switch (iAdd)
		{
		case 1:
			i = 0;
			break;
		case -1:
			i = 3;
			break;
		default:
			break;
		}

		switch (yAdd)
		{
		case 1:
			y = 0;
			break;
		case -1:
			y = 3;
			break;
		default:
			break;
		}


		for (i; i < 4; i + iAdd) {
			for (y; y < 3; y + yAdd) {
				if (grid[i + iAdd][y + yAdd] == 0) {
					grid[i + iAdd][y + yAdd] = grid[i][y];
					grid[i][y] = 0;
				} else if (grid[i + iAdd][y + yAdd] == grid[i][y]) {
					grid[i + iAdd][y + yAdd] = grid[i][y]^2;
					grid[i][y] = 0;
				}
			}
		}
	}
}

void Game::render() {

	grid[1][1] = 2;
	for (int x = 0; x < 4; x++)
		std::cout << " _";
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
	{
		std::cout << "|";
		for (int j = 0; j < 4; j++)
		{
			switch (grid[i][j])
			{
			case 0:
				std::cout << "  ";
				break;

			default:
				std::cout << grid[i][j] << " ";
				break;
			}
		}
		std::cout << "|\n";
	}
	for (int x = 0; x < 4; x++)
		std::cout << " _";
}