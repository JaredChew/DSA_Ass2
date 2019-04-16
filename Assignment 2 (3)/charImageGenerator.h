#pragma once

#include "gameSettings.h"

#define PIPE_SIZE_W 3
#define PIPE_SIZE_H 3

#define SELECTOR_SIZE_W 5
#define SELECTOR_SIZE_H 5

struct CharImageGenerator {

	static int** generateStraightPipe();
	static int** generate_LShapePipe();
	static int** generate_tShapePipe();

	static int** generateSartExitPoint();
	static int** generateSelector();
	static int** generateGrid();

};