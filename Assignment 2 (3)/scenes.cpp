#include "scenes.h"

void Scenes::displayHighScore() {

	//

}

bool Scenes::quitMenu() {

	char choice = ' ';

	while (true) {

		std::cout << "Quit game? (y/n): ";
		std::cin >> choice;

		switch (choice) {

		case 'Y':
		case 'y':
			return true;

		case 'N':
		case 'n':
			return false;

		default:
			std::cout << "\nOption not recognised. Please try again\n" << std::endl;

		}

	}

}

GameState Scenes::mainMenuFlow() {

	char choice = ' ';

	std::cout << "\tLIGHTS UP\n";

	std::cout << "\nConnect the circuits to light up the path\n";

	//displayHighScore();

	std::cout << "\n\nWould you like to play? (y/n): ";
	std::cin >> choice;

	switch (choice) {

		case 'Y':
		case 'y':
			return GameState::stage1;

		case 'N':
		case 'n':
			return GameState::endState;

		default:
			std::cout << "\nOption not recognised. Please try again" << std::endl;

	}

	return GameState::nullState;

}

GameState Scenes::gameOverFlow() {

	std::cout << "\nGame Over" << std::endl;

	return GameState::nullState;

}

GameState Scenes::gameBeatedFlow() {

	std::cout << "Congragulations, YOU WON !!!" << std::endl;

	return GameState::nullState;

}