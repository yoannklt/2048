#include <iostream>
#include "game.hpp"

Game::Game() {}

Game::~Game() {}

void Game::handleEvents() {

}

void Game::update() {

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