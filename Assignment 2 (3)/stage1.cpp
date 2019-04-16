#include "stage1.h"

Stage1::Stage1() {

	selectorPosition = 0;

	selectorPositionX = 1;
	selectorPositionY = 1;

	rotateAttemps = 0;

	quitGame = false;

	{ //Start of temp scope

		// 0 - empty, 1 - start, 2 - end, 3 - straight pipe, 4 - T pipe, 5 - L pipe

		int mapInit[] = {

			0, 5, 4, 2, 5, 0,
			0, 3, 0, 0, 3, 0,
			0, 3, 0, 0, 3, 0,
			0, 5, 3, 5, 3, 0,
			1, 3, 3, 4, 4, 2,
			0, 5, 3, 5, 3, 0,
			0, 3, 0, 0, 3, 0,
			0, 3, 0, 0, 3, 0,
			0, 5, 4, 2, 5, 0,

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
				node[i] = new Pipe<PIPE_SIZE_W, PIPE_SIZE_H>(CharImageGenerator::generateStraightPipe(), COLORS::YELLOW,
															 PipeShape::straight, RotationState::rotation0, false);
				break;

			case 4: //T-shape
				node[i] = new Pipe<PIPE_SIZE_W, PIPE_SIZE_H>(CharImageGenerator::generate_tShapePipe(), COLORS::YELLOW,
															 PipeShape::t_shaped, RotationState::rotation0, false);
				break;

			case 5: //L-shape
				node[i] = new Pipe<PIPE_SIZE_W, PIPE_SIZE_H>(CharImageGenerator::generate_LShapePipe(), COLORS::YELLOW,
															 PipeShape::l_shaped, RotationState::rotation0, false);
				break;


		}

	}

	//selector = CharSprite<Node_Space_W, Node_Space_H>(CharImageGenerator::generateSelector(), COLORS::CYAN);

	selector.setImage(CharImageGenerator::generateSelector());
	selector.setColour(COLORS::CYAN);

}

Stage1::~Stage1() { }

void Stage1::updatePipeColour(const int &index, const bool& isConnected) {

	if (isConnected) { node[index]->setColour(COLORS::LIGHTGREEN); }
	else { node[index]->setColour(COLORS::YELLOW); }

}

void Stage1::checkNorth(const int &index, const bool& type) {

	if (index < STG1_MAP_W) {
		return;
	}

	if (node[index - STG1_MAP_W]->getNortConnection()) {

		node[index - STG1_MAP_W]->setIsConnected(type);

		updatePipeColour(index - STG1_MAP_W, type);

	}

}

void Stage1::checkEast(const int& index, const bool& type) {

	if ((index + 1) % STG1_MAP_W == 0) {
		return;
	}

	if (node[index +1]->getEastConnection()) {

		node[index + 1]->setIsConnected(type);

		updatePipeColour(index + 1, type);

	}

}

void Stage1::checkSouth(const int& index, const bool& type) {

	if (index > ( (sizeof(node) / sizeof(node[0]) ) - STG1_MAP_W) ) {
		return;
	}

	if (node[index + STG1_MAP_W]->getSouthConnection()) {

		node[index + STG1_MAP_W]->setIsConnected(type);

		updatePipeColour(index + STG1_MAP_W, type);

	}

}

void Stage1::checkWest(const int& index, const bool& type) {

	if (index % STG1_MAP_W == 0) {
		return;
	}

	if (node[index - 1]->getWestConnection()) {

		node[index - 1]->setIsConnected(type);

		updatePipeColour(index - 1, type);

	}

}

void Stage1::checkPipeConnection(const bool& checkNewConnection) {

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

bool Stage1::cursorBorder(int x, int y) {

	//North
	if (y < 1) {
		return false;
	}

	//East
	if (x + 1 > ((STG1_MAP_W) * Node_Space_W)) {
		return false;
	}

	//South
	if (y + 1 > ((STG1_MAP_H) * Node_Space_H)) {
		return false;
	}

	//West
	if (x < 0) {
		return false;
	}

	return true;

}

void Stage1::rotateNode() {

	if (node[selectorPosition] != nullptr) {
		
		if (node[selectorPosition]->getPipeShape() != PipeShape::nullShape) {

			node[selectorPosition]->rotatePipe90();

			rotateAttemps++;

		}

	}

}

void Stage1::controls() {

	while (true) {

		
		if(Keyboard::keyIsPressed_v2(VK_UP)) {//if (Keyboard::keyIsPressed(KEY_W))

			selectorPosition -= STG1_MAP_H;

			selectorPositionY--;

			break;

		}
		else if (Keyboard::keyIsPressed_v2(VK_RIGHT)) { //Keyboard::keyIsPressed(KEY_D)

			selectorPosition++;

			selectorPositionX++;

			break;

		}
		else if (Keyboard::keyIsPressed_v2(VK_DOWN)) { //Keyboard::keyIsPressed(KEY_S)

			selectorPosition += STG1_MAP_H;

			selectorPositionY++;
			
			break;

		}
		else if (Keyboard::keyIsPressed_v2(VK_LEFT)) { //Keyboard::keyIsPressed(KEY_A)
			
			selectorPosition--;

			selectorPositionX--;

			break;

		}

		if (Keyboard::keyIsPressed_v2(VK_SPACE)) {

			rotateNode();

			rotateAttemps++;

			break;

		}

		if (Keyboard::keyIsPressed_v2(VK_ESCAPE)) {

			system("cls");
			textcolor(COLORS::WHITE);

			quitGame = Scenes::quitMenu();

			break;

		}

		Sleep(65);

	}

}

void Stage1::display() {

	int cursorPosX = (selectorPositionX * Node_Space_W) - SELECTOR_SPACE_COMPEN_W;
	int cursorPosY = (selectorPositionY * Node_Space_H) - SELECTOR_SPACE_COMPEN_H;
	
	if (cursorBorder(cursorPosX, cursorPosY)) {
		selector.render(cursorPosX, cursorPosY);
	}
	
	for (int i = 0, rowCounter = 2, colCounter = 2; i < sizeof(node) / sizeof(node[0]); i++, rowCounter += Node_Space_W) {

		if (node[i] != nullptr) {
			node[i]->render(rowCounter, colCounter);
		}

		if ((i + 1) % STG1_MAP_W == 0) {
			colCounter += 5;
			rowCounter = 2;
		}

	}
	
	textcolor(COLORS::WHITE);
	
	std::cout << "\nRotate the circuits to connect them nand light up the path\n";

	std::cout << "\n\n\tControls*:\n";
	std::cout << "\nPress UP DOWN LEFT RIGHT to move\nPress SPACE to rotate 90 degree clockwise\nPress ESC to quit game\n";

	std::cout << "\n*You may need to long press the key to register the input\n";

	std::cout << "\n\n!!! DO NOT ROATE DURING YOUR FIRST TURN !!!\n";

	std::cout << "\n\nNumber of rotations: " << rotateAttemps << std::endl;
	
}

GameState Stage1::flow() {

	//checkPipeConnection(true);
	display();
	controls();

	if (selectorPosition <= 0) { selectorPosition += (STG1_MAP_W * STG1_MAP_H); }
	else if (selectorPosition >= (STG1_MAP_W * STG1_MAP_H)) { selectorPosition -= (STG1_MAP_W * STG1_MAP_H); }

	if (selectorPositionX < 1) { selectorPositionX = STG1_MAP_W * Node_Space_W; }
	else if (selectorPositionX > (STG1_MAP_W * Node_Space_W)) { selectorPositionX = 1; }

	if (selectorPositionY < 1) { selectorPositionY = STG1_MAP_H * Node_Space_H; }
	else if (selectorPositionY > (STG1_MAP_H * Node_Space_H)) { selectorPositionY = 1; }

	if (quitGame) { return GameState::endState; }

	//checkPipeConnection(false);

	return GameState::nullState;

}