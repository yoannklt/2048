#pragma once

class Game
{
public:
	Game();
	~Game();

	void handleEvent();
	void update();
	void render();
	
	bool running() { return isRunning; }

private:
	int grid[4][4] = { 0 };
	bool isRunning;

};