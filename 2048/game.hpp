#pragma once

#include <vector>

class Game
{
public:
	Game();
	~Game();

	void init();
	void handleEvents();
	void update();
	void render();
	void clear();
	void checkEmptyCell();
	int randomValue();
	
	bool running() { return isRunning; }

private:
	int grid[4][4] = { 0 };
	bool isRunning;
	int directionVect[2] = { 0, 0 };

};