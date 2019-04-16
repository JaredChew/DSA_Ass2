#include <iostream>

#include "game.h"

int main() {

	Game *game = new Game();

	while (game->getGameLoop()) {

		game->gameFlow();

	}

	delete game;

	return 0;

}