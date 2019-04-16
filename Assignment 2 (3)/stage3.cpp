#include "stage3.h"

Stage3::Stage3() {

	selectorPosition = 0;
	rotateAttemps = 0;

	quitGame = false;

	{ //Start of temp scope

		// 0 - empty, 1 - start, 2 - end, 3 - straight pipe, 4 - T pipe, 5 - L pipe

		int mapInit[] = {

			0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0,

		};

		for (int i = 0; i < sizeof(mapInit) / sizeof(mapInit[0]); i++) {

			map.push_back(mapInit[i]);

		}

	} //End of temp scope

	for (unsigned int i = 0; i < map.size(); i++) {

		switch (map[i]) {

		case 1: //Start		
			node[i] = new Pipe<PIPE_SIZE_W, PIPE_SIZE_H>(CharImageGenerator::generateSartExitPoint(), COLORS::LIGHTRED,
				PipeShape::nullShape, RotationState::rotation0, false);
			break;

		case 2: //End
			node[i] = new Pipe<PIPE_SIZE_W, PIPE_SIZE_H>(CharImageGenerator::generateSartExitPoint(), COLORS::GREEN,
				PipeShape::nullShape, RotationState::rotation0, true);
			break;

		case 3: //Straight
			node[i] = new Pipe<PIPE_SIZE_W, PIPE_SIZE_H>(CharImageGenerator::generateSartExitPoint(), COLORS::YELLOW,
				PipeShape::straight, RotationState::rotation0, false);
			break;

		case 4: //T-shape
			node[i] = new Pipe<PIPE_SIZE_W, PIPE_SIZE_H>(CharImageGenerator::generateSartExitPoint(), COLORS::YELLOW,
				PipeShape::t_shaped, RotationState::rotation0, false);
			break;

		case 5: //L-shape
			node[i] = new Pipe<PIPE_SIZE_W, PIPE_SIZE_H>(CharImageGenerator::generateSartExitPoint(), COLORS::YELLOW,
				PipeShape::l_shaped, RotationState::rotation0, false);
			break;


		}

	}

	pipeShape_T.setPipeImage(CharImageGenerator::generate_tShapePipe());
	pipeShape_T.setColour(COLORS::YELLOW);

	pipeShape_L.setPipeImage(CharImageGenerator::generate_LShapePipe());
	pipeShape_L.setColour(COLORS::YELLOW);

	pipeShape_Straight.setPipeImage(CharImageGenerator::generateStraightPipe());
	pipeShape_Straight.setColour(COLORS::YELLOW);

	exitPoint.setPipeImage(CharImageGenerator::generateSartExitPoint());
	exitPoint.setColour(COLORS::LIGHTRED);

	startPoint.setPipeImage(CharImageGenerator::generateSartExitPoint());
	startPoint.setColour(COLORS::GREEN);

	selector.setImage(CharImageGenerator::generateSelector());
	selector.setColour(COLORS::CYAN);

}

Stage3::~Stage3() { }

void Stage3::updatePipeColour(const int& index, const bool& isConnected) {

	if (isConnected) { node[index]->setColour(COLORS::LIGHTGREEN); }
	else { node[index]->setColour(COLORS::YELLOW); }

}

void Stage3::checkNorth(const int& index, const bool& type) {

	if (index < STG1_MAP_W) {
		return;
	}

	if (node[index - STG1_MAP_W]->getNortConnection()) {

		node[index - STG1_MAP_W]->setIsConnected(type);

		updatePipeColour(index - STG1_MAP_W, type);

	}

}

void Stage3::checkEast(const int& index, const bool& type) {

	if ((index + 1) % STG1_MAP_W == 0) {
		return;
	}

	if (node[index + 1]->getEastConnection()) {

		node[index + 1]->setIsConnected(type);

		updatePipeColour(index + 1, type);

	}

}

void Stage3::checkSouth(const int& index, const bool& type) {

	if (index > ((sizeof(node) / sizeof(node[0])) - STG1_MAP_W)) {
		return;
	}

	if (node[index + STG1_MAP_W]->getSouthConnection()) {

		node[index + STG1_MAP_W]->setIsConnected(type);

		updatePipeColour(index + STG1_MAP_W, type);

	}

}

void Stage3::checkWest(const int& index, const bool& type) {

	if (index % STG1_MAP_W == 0) {
		return;
	}

	if (node[index - 1]->getWestConnection()) {

		node[index - 1]->setIsConnected(type);

		updatePipeColour(index - 1, type);

	}

}

void Stage3::checkPipeConnection(const bool& checkNewConnection) {

	for (int i = 0; i < sizeof(node) / sizeof(node[i]); i++) {

		if (node[i] != nullptr) {

			if (node[i]->getIsConnected() == checkNewConnection) {

				checkNorth(i, checkNewConnection);
				checkEast(i, checkNewConnection);
				checkSouth(i, checkNewConnection);
				checkWest(i, checkNewConnection);

			}

		}

	}

}

void Stage3::rotateNode() {

	if (node[selectorPosition] != nullptr) {

		if (node[selectorPosition]->getPipeShape() != PipeShape::nullShape) {

			node[selectorPosition]->rotatePipe90();

			rotateAttemps++;

		}

	}

}

void Stage3::controls() {

	while (true) {

		if (Keyboard::keyIsPressed(KEY_W)) {

			selectorPosition -= STG1_MAP_H;

			break;

		}
		else if (Keyboard::keyIsPressed(KEY_D)) {

			selectorPosition++;

			break;

		}
		else if (Keyboard::keyIsPressed(KEY_S)) {

			selectorPosition += STG1_MAP_H;

			break;

		}
		else if (Keyboard::keyIsPressed(KEY_A)) {

			selectorPosition--;

			break;

		}

		if (Keyboard::keyIsPressed(KEY_SPACE)) {

			rotateNode();

			pipeShape_T.rotatePipe90();
			pipeShape_L.rotatePipe90();
			pipeShape_Straight.rotatePipe90();

			rotateAttemps++;

			break;

		}

		if (Keyboard::keyIsPressed(KEY_ESCAPE)) {

			system("cls");
			textcolor(COLORS::WHITE);

			quitGame = Scenes::quitMenu();

			break;

		}

	}

}

void Stage3::display() {

	//selector.render();

	for (int i = 0; i < sizeof(node) / sizeof(node[0]); i++) {

		if (node[i] != nullptr) {
			//node[i]->render();
		}

	}

	pipeShape_T.render(1, 1);
	pipeShape_L.render(6, 1);
	pipeShape_Straight.render(11, 1);
	exitPoint.render(16, 1);
	startPoint.render(21, 1);

	textcolor(COLORS::WHITE);

	std::cout << "\nRotate the pipes to get the water to flow to the exit points.\n";

	std::cout << "\n\n\tControls*:\n";
	std::cout << "\nPress WASD to move\nPress SPACE to rotate 90 degree clockwise\nPress ESC to quit game\n";

	std::cout << "\n*You may need to long press the key to register the input\n";

	std::cout << "\n\n!!! DO NOT ROATE DURING YOUR FIRST TURN !!!\n";

	std::cout << "\n\nNumber of rotations: " << rotateAttemps << std::endl;

}

GameState Stage3::flow() {

	checkPipeConnection(true);
	display();
	controls();

	if (selectorPosition <= 0) { selectorPosition += (STG1_MAP_W * STG1_MAP_H); }
	else if (selectorPosition >= (STG1_MAP_W * STG1_MAP_H)) { selectorPosition -= (STG1_MAP_W * STG1_MAP_H); }

	if (quitGame) { return GameState::endState; }

	checkPipeConnection(false);

	return GameState::nullState;

}