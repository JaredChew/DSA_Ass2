#pragma once

#include <iostream>

#include "gameSettings.h"

struct Scenes {

	static void displayHighScore();

	static bool quitMenu();

	static GameState mainMenuFlow();
	static GameState gameOverFlow();
	static GameState gameBeatedFlow();

};