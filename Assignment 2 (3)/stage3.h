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

class Stage3 {

private:
	Pipe<PIPE_SIZE_W, PIPE_SIZE_H> pipeShape_T;
	Pipe<PIPE_SIZE_W, PIPE_SIZE_H> pipeShape_L;
	Pipe<PIPE_SIZE_W, PIPE_SIZE_H> pipeShape_Straight;

	Pipe<PIPE_SIZE_W, PIPE_SIZE_H> exitPoint;
	Pipe<PIPE_SIZE_W, PIPE_SIZE_H> startPoint;

	//CharSprite<STG1_MAP_W, STG1_MAP_H> grid;
	CharSprite<Node_Space_W, Node_Space_H> selector;

	//LinkedList<Pipe<PIPE_SIZE_W, PIPE_SIZE_H>> node;
	//std::vector<Pipe<PIPE_SIZE_W, PIPE_SIZE_H>> node;
	Pipe<PIPE_SIZE_W, PIPE_SIZE_H>* node[STG1_MAP_H * STG1_MAP_W];

	std::vector<int> map;
	//int **grid;

	int selectorPosition;
	int rotateAttemps;

	bool quitGame;

private:
	void updatePipeColour(const int& index, const bool& isConnected);

	void checkNorth(const int& index, const bool& type);
	void checkEast(const int& index, const bool& type);
	void checkSouth(const int& index, const bool& type);
	void checkWest(const int& index, const bool& type);

	void checkPipeConnection(const bool& checkNewConnection);

	void rotateNode();
	void controls();

	void renderGrid();
	void display();

public:
	Stage3();
	~Stage3();

	GameState flow();

};