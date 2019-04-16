#pragma once

#include <iostream>
#include <vector>
#include <array>

#include "gameSettings.h"
#include "charSprites.hpp"
#include "pipes.hpp"
#include "charImageGenerator.h"
#include "keyboard.h"
#include "scenes.h"
//#include "linkedList.hpp"

class Stage1 {

private:
	CharSprite<Node_Space_W, Node_Space_H> selector;

	Pipe<PIPE_SIZE_W, PIPE_SIZE_H>* node[STG1_MAP_H * STG1_MAP_W];

	std::vector<int> map;
	//int **grid;

	int selectorPosition;

	int selectorPositionX;
	int selectorPositionY;

	int rotateAttemps;

	bool quitGame;

private:
	void updatePipeColour(const int& index, const bool &isConnected);

	void checkNorth(const int& index, const bool &type);
	void checkEast(const int& index, const bool& type);
	void checkSouth(const int& index, const bool& type);
	void checkWest(const int& index, const bool& type);

	void checkPipeConnection(const bool& checkNewConnection);

	bool cursorBorder(int x, int y);

	void rotateNode();
	void controls();

	void renderGrid();
	void display();

public:
	Stage1();
	~Stage1();

	GameState flow();

};