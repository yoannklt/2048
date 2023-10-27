#pragma once 

#include "cell.hpp"
#include <vector>

class Grid {
public:
	Grid();
	~Grid() {};

	int randomValue();
	void generateRandomCell(int i = -1);
	bool hasLost() { return lost; };
	void render();
	void slide();
	void setVect(int x, int y) { directionVect[0] = x; directionVect[1] = y; };

	void swapCell(Cell** cell1, Cell** cell2);
	 
private:
	bool lost = false;
	std::vector<Cell*> emptyCellGrid;
	int directionVect[2] = { 0, 0 };

protected:
	Cell* tab[4][4];

};