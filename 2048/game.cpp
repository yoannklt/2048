#include <iostream>
#include "game.hpp"

Game::Game() {
	grid[1][0] = 2;
	grid[1][1] = 2;
	grid[1][2] = 2;
	grid[1][3] = 2;
}

Game::~Game() {}

void Game::handleEvents() {

}

void Game::update() {
	bool isMoving = true;
	int i = 0;
	int y = 0;
	int iAdd = 0;
	int yAdd = 0;
	int indexOne = 0;
	int indexOneNext = 0;
	int indexTwo = 0;
	int indexTwoNext = 0;
	if (directionVect[1] == -1) {
		iAdd = 3;
	}
	else if (directionVect[0] == -1) {
		yAdd = 3;
	}

	for (i; i < 4; i++) {
		y = 0;
		for (y; y < 3; y++) {
			indexOne = y * directionVect[1] + iAdd + i * directionVect[0];
			indexOneNext = (y + 1) * directionVect[1] + iAdd + i * directionVect[0];

			indexTwo = y * directionVect[0] + yAdd + i * directionVect[1];
			indexTwoNext = (y + 1) * directionVect[0] + yAdd + i * directionVect[1];

			if (this->grid[indexOneNext][indexTwoNext] == 0 and this->grid[indexOne][indexTwo] != 0) {

				this->grid[indexOneNext][indexTwoNext] = this->grid[indexOne][indexTwo];
				this->grid[indexOne][indexTwo] = 0;
			}
			else if (this->grid[indexOneNext][indexTwoNext] == this->grid[indexOne][indexTwo] and this->grid[indexOne][indexTwo] != 0) {
				this->grid[indexOneNext][indexTwoNext] = this->grid[indexOne][indexTwo] * this->grid[indexOneNext][indexTwoNext];
				this->grid[indexOne][indexTwo] = 0;
				y++;
			}
		}

		y = 0;
		for (y; y < 3; y++) {
			indexOne = y * directionVect[1] + iAdd + i * directionVect[0];
			indexOneNext = (y + 1) * directionVect[1] + iAdd + i * directionVect[0];

			indexTwo = y * directionVect[0] + yAdd + i * directionVect[1];
			indexTwoNext = (y + 1) * directionVect[0] + yAdd + i * directionVect[1];

			if (this->grid[indexOneNext][indexTwoNext] == 0 and this->grid[indexOne][indexTwo] != 0) {
				this->grid[indexOneNext][indexTwoNext] = this->grid[indexOne][indexTwo];
				this->grid[indexOne][indexTwo] = 0;
			}
		}
	}
}

void Game::render() {
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
	while(true) {}
}