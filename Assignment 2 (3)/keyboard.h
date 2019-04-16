#pragma once

#include <windows.h>

#include "conio_yp.h"

#define KEY_ESCAPE 27
#define KEY_SPACE 32

#define KEY_W 119
#define KEY_D 100
#define KEY_S 115
#define KEY_A 97

struct Keyboard {

	static bool keyIsPressed(unsigned const char& key);

	static bool keyIsPressed_v2(const int &keyCode);

};