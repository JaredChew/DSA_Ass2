#pragma once

#include <iostream>

#include "conio_yp.h"

template<int row, int col>
class CharSprite {

private:
	int **image;

	COLORS currentColour;
	COLORS originalColour;

protected:
	int** getImage() const {

		return image;

	}

public:
	CharSprite() {

		image = new int*[row * col];

		originalColour = COLORS::WHITE;
		currentColour = originalColour;

	}

	CharSprite(int* image[row * col], COLORS colour) {

		image = new int* [row * col];

		this->image = image;

		originalColour = colour;
		currentColour = originalColour;

	}

	~CharSprite() { }

	void setImage(int *image[row * col]) {

		this->image = image;

	}

	void render(int x, int y) { //

		gotoxy(x, y);

		textcolor(currentColour);

		for (int i = 0, colCounter = 0; i < (row * col); i++) {

			if (*image[i] != 0) { std::cout << "#"; }
			else { std::cout << " "; }

			colCounter++;

			if (colCounter >= col) {

				y += 1;

				gotoxy(x, y);

				colCounter = 0;

			}

		}

	}

	//Rotates image 90 clockwise, !!! Only for images size 3x3 !!!
	void rotateImage3x3() {

		int **temp = new int*[row * col];

		for (int i = 0; i < (row * col); i++) {

			temp[i] = image[i];

		}

		image[0] = temp[6];
		image[1] = temp[3];
		image[2] = temp[0];
		image[3] = temp[7];

		//image 4 center point - no rotation

		image[5] = temp[1];
		image[6] = temp[8];
		image[7] = temp[5];
		image[8] = temp[2];

	}
	void setColour(COLORS colour) {

		originalColour = colour;
		currentColour = originalColour;

	}

	void setOriginalColour(COLORS originalColour) {

		this->originalColour = originalColour;

	}

	void setCurrentColour(COLORS currentColour) {

		this->currentColour = currentColour;

	}

};

/*

void rotateImage3x3_dynamic(const int &cycles) { //Only for images size 3x3

	//	!!! Find math to dynamically rotate !!!

	//Higher function needs to calculate cycles to rotation to selected position

	const int CENTER_POINT = 4;
	const int IMAGE_INDEX_END = 8;

	int index = 0;
	int currentCycle = 0;
	int indexToPintTo = 0;

	while (currentCycle != cycles) {

		if (index == CENTER_POINT) {
			index++;
			continue;
		}

		indexToPintTo = index + 5;

		if (indexToPintTo > 8) {
			indexToPintTo -= (row * col);
		}

		if (image[index] > 0) {
			*image[indexToPintTo] += 1;
			*image[index] = 0;
		}

		index++;

		if (index == IMAGE_INDEX_END) {

			index = 0;

			currentCycle++;

		}

	}

	for (int i = 0; i < (row * col); i++) {

		if (*image[i] > 1) {
			*image[i] = 1;
		}

	}

}
*/

/*

				Static rotation cheat sheet

			
	Anti-clockwise {

		image[0] = temp2;
		image[1] = temp5;
		image[2] = temp8;
		image[3] = temp1;

		//image 4 center point - no rotation

		image[5] = temp7;
		image[6] = temp0;
		image[7] = temp3;
		image[8] = temp6;

	}

	Mirror {

		image[0] = temp8;
		image[1] = temp7;
		image[2] = temp6;
		image[3] = temp5;

		//image 4 center point - no rotation

		image[5] = temp3;
		image[6] = temp2;
		image[7] = temp1;
		image[8] = temp0;

	}

*/