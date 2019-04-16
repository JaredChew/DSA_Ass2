#include "charImageGenerator.h"

int** CharImageGenerator::generateStraightPipe() {

	static int *straightPipe[] = {

		new int(0), new int(0), new int(0),
		new int(1), new int(1), new int(1),
		new int(0), new int(0), new int(0)

	};

	return straightPipe;

}

int** CharImageGenerator::generate_LShapePipe() {

	static int *L_ShapedPipe[] = {

		new int(0), new int(1), new int(0),
		new int(0), new int(1), new int(1),
		new int(0), new int(0), new int(0)

	};

	return L_ShapedPipe;

}

int** CharImageGenerator::generate_tShapePipe() {

	static int *T_ShapedPipe[] = {

		new int(0), new int(0), new int(0),
		new int(1), new int(1), new int(1),
		new int(0), new int(1), new int(0)

	};

	return T_ShapedPipe;

}

int** CharImageGenerator::generateSartExitPoint() {

	static int *exitPoint[] = {

		new int(1), new int(1), new int(1),
		new int(1), new int(1), new int(1),
		new int(1), new int(1), new int(1)

	};

	return exitPoint;

}

int** CharImageGenerator::generateSelector() {

	static int* selector[] = {

		new int(1), new int(1), new int(1), new int(1), new int(1),
		new int(1), new int(0), new int(0), new int(0), new int(1),
		new int(1), new int(0), new int(0), new int(0), new int(1),
		new int(1), new int(0), new int(0), new int(0), new int(1),
		new int(1), new int(1), new int(1), new int(1), new int(1)

	};

	return selector;

}