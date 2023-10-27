#pragma once

#include <iostream>
#include <conio.h>
#include <vector>

#include "grid.hpp"

class Game
{
	Grid grid;

public:
	Game();
	~Game();

	void handleEvents();
	void update();
	void render();
	
	bool running() { return isRunning; }

private:
	bool isRunning = true;
	

};