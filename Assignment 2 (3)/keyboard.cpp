#include "keyboard.h"

bool Keyboard::keyIsPressed(unsigned const char &key) {

	char input = getch();

	if (input == key) {
		return true;
	}

	return false;

}

bool Keyboard::keyIsPressed_v2(const int& keyCode) {

	if (GetKeyState(keyCode) & 0x8000) {
		return true;
	}

	return false;

}