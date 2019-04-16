#pragma once

#include <iostream>
#include "windows.h"

#include "gameSettings.h"

#include "scenes.h"

#include "stage1.h"
#include "stage2.h"
#include "stage3.h"

class Game {

private:
	Stage1 *stage1;
	Stage2 *stage2;
	Stage3 *stage3;

	GameState currentState;
	GameState nextState;
	GameState returnedState;

	bool gameLoop;

private:
	void clearInputBuffer();

	void stateDestroyer();
	void stateInitialiser();
	void flowControl();

public:
	Game();
	~Game();

	bool getGameLoop();

	void gameFlow();

};