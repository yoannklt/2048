#include <iostream>
#include "game.hpp"

Game::Game() {

}

Game::~Game() {}

void Game::handleEvents() {
}

void Game::update() {

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