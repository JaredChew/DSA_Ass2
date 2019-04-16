#include "game.h"

Game::Game() : stage1(nullptr), stage2(nullptr), stage3(nullptr) {

	gameLoop = true;

	currentState = GameState::mainMenu;
	nextState = GameState::nullState;
	returnedState = GameState::nullState;

}

Game::~Game() {

	if (stage1 != nullptr) {
		delete stage1;
		stage1 = nullptr;
	}

	if (stage2 != nullptr) {
		delete stage2;
		stage2 = nullptr;
	}

	if (stage3 != nullptr) {
		delete stage3;
		stage3 = nullptr;
	}

}

void Game::clearInputBuffer() {

	std::cout.flush();
	std::cin.ignore();
	std::cin.clear();

}

bool Game::getGameLoop() {

	return gameLoop;

}

void Game::stateDestroyer() {

	switch (currentState) {

		case GameState::stage1:
			delete stage1;
			stage1 = nullptr;
			break;

		case GameState::stage2:
			delete stage2;
			stage2 = nullptr;
			break;

		case GameState::stage3:
			delete stage3;
			stage3 = nullptr;
			break;

	}

}

void Game::stateInitialiser() {

	switch (nextState) {

		case GameState::stage1:
			stage1 = new Stage1();
			break;

		case GameState::stage2:
			stage2 = new Stage2();
			break;

		case GameState::stage3:
			stage3 = new Stage3();
			break;

		case GameState::endState:
			gameLoop = false;
			break;

	}

	stateDestroyer();

	currentState = nextState;
	nextState = GameState::nullState;

}

void Game::flowControl() {

	switch (currentState) {

		case GameState::mainMenu:
			returnedState = Scenes::mainMenuFlow();
			break;

		case GameState::stage1:
			returnedState = stage1->flow();
			break;

		case GameState::stage2:
			returnedState = stage2->flow();
			break;

		case GameState::stage3:
			returnedState = stage3->flow();
			break;

		case GameState::gameBeaten:
			returnedState = Scenes::gameBeatedFlow();
			break;

	}

}

void Game::gameFlow() {

	flowControl();

	if (returnedState != GameState::nullState) {

		nextState = returnedState;
		returnedState = GameState::nullState;

		stateInitialiser();

	}

	std::cout << "\n";

	textcolor(COLORS::WHITE);

	//clearInputBuffer();
	system("cls");

}