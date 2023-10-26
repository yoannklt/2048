#pragma once 
#include "game.hpp"
#include "cell.hpp"

class Grid {
public:
	Grid();
	~Grid() {};

	int randomValue();
	void generateRandomCell();
	bool hasLost() { return lost; };
	void render();
	void slide();

private:
	Cell tab[4][4]; 
	bool lost = false;
	std::vector<Cell*> emptyCellGrid;
};