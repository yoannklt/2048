#include <iostream>
#include <conio.h>
#include "game.hpp"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

Game::Game() {
	checkEmptyCell();
	checkEmptyCell();
}

Game::~Game() {}

void Game::handleEvents() {
	if (lost)
		isRunning = false;

	std::cout << std::endl << "Swipe in any direction using arrow keys " << std::endl;

	bool badKey = true;
	while (badKey)
	{
		badKey = false;
		int c = 0; 
		switch ((c = _getch() ))
		{
		case KEY_UP: 
			directionVect[1] = -1;
			directionVect[0] = 0;
			slide();
			break;

		case KEY_DOWN: 
			directionVect[1] = 1;
			directionVect[0] = 0;
			slide();
			break;

		case KEY_LEFT: 
			directionVect[0] = -1;
			directionVect[1] = 0;
			slide();
			break;

		case KEY_RIGHT: 
			directionVect[0] = 1;
			directionVect[1] = 0;
			slide();
			break;

		default:
			badKey = true;
			break;
		}
	}
	

}

void Game::update() {
	checkEmptyCell();
	if (lost) {
		isRunning = false;
		std::cout << std::endl << "Perdu c'est CIAOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << std::endl;
	}
}

void Game::render() {

	system("cls");

	if (lost) {
		return;
	}
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
	{
		std::cout << " " << "-----------------" << std::endl << " | ";
		for (int j = 0; j < 4; j++)
		{
			switch (grid[i][j])
			{
			case 0:
				std::cout << "  | ";
				break;

			default:
				std::cout << grid[i][j] << " | ";
				break;
			}
		}
		std::cout << std::endl;

	}
	std::cout << " " << "-----------------" << std::endl;
}

void Game::slide() {
	int i = 0;
	int y = 0;
	int j = 0;
	int iAdd = 0;
	int yAdd = 0;
	int indexOne = 0;
	int indexOneNext = 0;
	int indexTwo = 0;
	int indexTwoNext = 0;
	bool isMoving = true;
	if (directionVect[1] == -1) {
		iAdd = 3;
	}
	else if (directionVect[0] == -1) {
		yAdd = 3;
	}

	for (i; i < 4; i++) {
		y = 0;
		for (y; y < 3; y++) {
			indexOne = y * directionVect[1] + iAdd + i * (directionVect[0] * directionVect[0]);
			indexOneNext = (y + 1) * directionVect[1] + iAdd + i * (directionVect[0] * directionVect[0]);

			indexTwo = y * directionVect[0] + yAdd + i * (directionVect[1] * directionVect[1]);
			indexTwoNext = (y + 1) * directionVect[0] + yAdd + i * (directionVect[1] * directionVect[1]);

			if (this->grid[indexOneNext][indexTwoNext] == 0 and this->grid[indexOne][indexTwo] != 0) {

				this->grid[indexOneNext][indexTwoNext] = this->grid[indexOne][indexTwo];
				this->grid[indexOne][indexTwo] = 0;
			}
			else if (this->grid[indexOneNext][indexTwoNext] == this->grid[indexOne][indexTwo] and this->grid[indexOne][indexTwo] != 0) {
				this->grid[indexOneNext][indexTwoNext] = this->grid[indexOne][indexTwo] * 2;
				this->grid[indexOne][indexTwo] = 0;
				y++;
			}
		}

		isMoving = true;
		j = 0;
		while (j < 2 and isMoving) {
			isMoving = false;
			j++;
			y = 0;
			for (y; y < 3; y++) {
				indexOne = y * directionVect[1] + iAdd + i * (directionVect[0] * directionVect[0]);
				indexOneNext = (y + 1) * directionVect[1] + iAdd + i * (directionVect[0] * directionVect[0]);

				indexTwo = y * directionVect[0] + yAdd + i * (directionVect[1] * directionVect[1]);
				indexTwoNext = (y + 1) * directionVect[0] + yAdd + i * (directionVect[1] * directionVect[1]);

				if (this->grid[indexOneNext][indexTwoNext] == 0 and this->grid[indexOne][indexTwo] != 0) {
					this->grid[indexOneNext][indexTwoNext] = this->grid[indexOne][indexTwo];
					this->grid[indexOne][indexTwo] = 0;
					isMoving = true;
				}
			}
		}
	}
}

int Game::randomValue()
{
	srand(static_cast<unsigned>(time(0)));

	int randomValue = (rand() % 2) == 0 ? 2 : 4; 
	return randomValue;
}

void Game::checkEmptyCell()
{
	int emptyCellNumber = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (grid[i][j] == 0)
				emptyCellNumber++;
		}
	}
	
	if (emptyCellNumber == 0) {
		this->lost = true;
		return;
	}

	int randomNumber = rand() % emptyCellNumber + 1;

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (grid[x][y] == 0)
			{
				randomNumber--;
				if (randomNumber == 0) {
					grid[x][y] = randomValue();
					return;
				}
			}
		}
	}
}

