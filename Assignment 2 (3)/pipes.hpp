#pragma once

#include "charSprites.hpp"

enum PipeShape {

	nullShape,
	straight,
	l_shaped,
	t_shaped

};

enum RotationState {

	rotation0,
	rotation90,
	rotation180,
	rotation270,

	first = rotation0,
	last = rotation270

};

template<int row, int col>
class Pipe : public CharSprite<row, col> {

private:
	PipeShape pipeShape;
	RotationState currentRotation;

	bool northConnection;
	bool eastConnection;
	bool southConnecion;
	bool westConnection;

	bool isConnected;

private:
	void updateConnections() {

		const int *const *const readImage = CharSprite<row, col>::getImage();

		//North
		for (int i = 0; i < row; i++) {

            if (*readImage[i] != 0) {
				northConnection = true;
				//break;
			}
			else if (i == row - 1) {
				eastConnection = false;
			}

		}

		//East
		for (int i = row - 1; i < row * col; i += row) {

			if (*readImage[i] != 0) {
				eastConnection = true;
				//break;
			}
			else if (i == (row * col) - 1) {
				eastConnection = false;
			}

		}

		//South
		for (int i = (row * col) - row; i < row * col; i++) {

			if (*readImage[i] != 0) {
				southConnecion = true;
				//break;
			}
			else if (i == (row * col) - 1) {
				southConnecion = false;
			}

		}

		//West
		for (int i = 0; i < (row * col); i += row) {

			if (*readImage[i] != 0) {
				westConnection = true;
				//break;
			}
			else if (i == (row * col) - (row - 1)) {
				westConnection = false;
			}

		}

	}

public:
	Pipe() {
;
		pipeShape = nullShape;
		currentRotation = rotation0;

		isConnected = false;

		northConnection = false;
		eastConnection = false;
		southConnecion = false;
		westConnection = false;

	}

	Pipe(int* image[row * col], COLORS colour, PipeShape pipeShape, RotationState currentRotation, bool isConnected) {

		CharSprite<row, col>::setImage(image);

		CharSprite<row, col>::setColour(colour);

		this->pipeShape = pipeShape;
		this->currentRotation = currentRotation;

		this->isConnected = isConnected;

		northConnection = false;
		eastConnection = false;
		southConnecion = false;
		westConnection = false;

		updateConnections();

	}

	~Pipe() {
	
		CharSprite<row, col>::~CharSprite();
	
	}

	void setPipeImage(int **image) {

		CharSprite<row, col>::setImage(image);

		updateConnections();

	}

	void rotatePipe90() {

		CharSprite<row, col>::rotateImage3x3();

		currentRotation = (RotationState)((int)currentRotation + 1);

		if (currentRotation > last) {
			currentRotation = first;
		}

		updateConnections();

	}

	bool getIsConnected() {

		return isConnected;

	}

	void setIsConnected(bool isConnected) {

		this->isConnected = isConnected;

	}

	PipeShape getPipeShape() {

		return pipeShape;

	}

	void setPipeShape(PipeShape pipeShape) {

		this->pipeShape = pipeShape;

	}

	RotationState getCurrentRotation() {

		return currentRotation;

	}

	void setCurrentRotation(RotationState currentRotation) {

		if (this->currentRotation == rotation270 && currentRotation == rotation0) {

			CharSprite<row, col>::rotateImage3x3();

		}
		else {

			for (int i = 0; i < abs(this->currentRotation); i++) {

				CharSprite<row, col>::rotateImage3x3();

			}

		}

		this->currentRotation = currentRotation;

	}

	bool getNortConnection() {
		return northConnection;
	}

	bool getEastConnection() {
		return eastConnection;
	}

	bool getSouthConnection() {
		return southConnecion;
	}

	bool getWestConnection() {
		return westConnection;
	}

};