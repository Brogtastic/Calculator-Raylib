#pragma once
#include <iostream>
#include <string>
#include "raylib.h"
#define print(x) cout << x
using namespace std;

extern int frameCount;
extern int blinkerCount;
extern int backSpaceCount;
extern int arrowKeyCount;
extern int fontSize;
extern float pixelTextMinus;
extern int cursorPos;
extern bool canType;

extern string buttonPress;

string GetUserInput(string stringUpdate) {

	if (canType == true) {
		if ((IsKeyPressed(KEY_ZERO) && (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT))) || buttonPress == "close") {
			stringUpdate.insert(cursorPos, ")");
			cursorPos += 1;
			blinkerCount = 0;
		}
		else if (IsKeyPressed(KEY_ZERO) || buttonPress == "zero") {
			stringUpdate.insert(cursorPos, "0");
			cursorPos += 1;
			blinkerCount = 0;
		}
		if (IsKeyPressed(KEY_ONE) || buttonPress == "one") {
			stringUpdate.insert(cursorPos, "1");
			cursorPos += 1;
			blinkerCount = 0;
		}
		if (IsKeyPressed(KEY_TWO) || buttonPress == "two") {
			stringUpdate.insert(cursorPos, "2");
			cursorPos += 1;
			blinkerCount = 0;
		}
		if (IsKeyPressed(KEY_THREE) || buttonPress == "three") {
			stringUpdate.insert(cursorPos, "3");
			cursorPos += 1;
			blinkerCount = 0;
		}
		if (IsKeyPressed(KEY_FOUR) || buttonPress == "four") {
			stringUpdate.insert(cursorPos, "4");
			cursorPos += 1;
			blinkerCount = 0;
		}
		if (IsKeyPressed(KEY_FIVE) || buttonPress == "five") {
			stringUpdate.insert(cursorPos, "5");
			cursorPos += 1;
			blinkerCount = 0;
		}
		if ((IsKeyPressed(KEY_SIX) && (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT))) || buttonPress == "exponent") {
			stringUpdate.insert(cursorPos, "^");
			cursorPos += 1;
			blinkerCount = 0;
		}
		else if (IsKeyPressed(KEY_SIX) || buttonPress == "six") {
			stringUpdate.insert(cursorPos, "6");
			cursorPos += 1;
			blinkerCount = 0;
		}
		if (IsKeyPressed(KEY_SEVEN) || buttonPress == "seven") {
			stringUpdate.insert(cursorPos, "7");
			cursorPos += 1;
			blinkerCount = 0;
		}
		if ((IsKeyPressed(KEY_EIGHT) && (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT))) || buttonPress == "multiply") {
			stringUpdate.insert(cursorPos, "*");
			cursorPos += 1;
			blinkerCount = 0;
		}
		else if (IsKeyPressed(KEY_EIGHT) || buttonPress == "eight") {
			stringUpdate.insert(cursorPos, "8");
			cursorPos += 1;
			blinkerCount = 0;
		}
		if ((IsKeyPressed(KEY_NINE) && (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT))) || buttonPress == "open") {
			stringUpdate.insert(cursorPos, "(");
			cursorPos += 1;
			blinkerCount = 0;
		}
		else if (IsKeyPressed(KEY_NINE) || buttonPress == "nine") {
			stringUpdate.insert(cursorPos, "9");
			cursorPos += 1;
			blinkerCount = 0;
		}
		if (IsKeyPressed(KEY_SPACE)) {
			stringUpdate.insert(cursorPos, " ");
			cursorPos += 1;
			blinkerCount = 0;
		}
		if ((IsKeyPressed(KEY_EQUAL) && (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT))) || buttonPress == "plus") {
			stringUpdate.insert(cursorPos, "+");
			cursorPos += 1;
			blinkerCount = 0;
		}
		if (IsKeyPressed(KEY_MINUS) || buttonPress == "minus") {
			stringUpdate.insert(cursorPos, "-");
			cursorPos += 1;
			blinkerCount = 0;
		}
		if (IsKeyPressed(KEY_SLASH) || buttonPress == "slash") {
			stringUpdate.insert(cursorPos, "/");
			cursorPos += 1;
			blinkerCount = 0;
		}
		if (IsKeyPressed(KEY_PERIOD) || buttonPress == "period") {
			stringUpdate.insert(cursorPos, ".");
			cursorPos += 1;
			blinkerCount = 0;
		}
	}
	if (IsKeyPressed(KEY_BACKSPACE)) {
		if ((stringUpdate.length() > 0) && (cursorPos > 0)) {
			stringUpdate.erase(cursorPos-1, 1);
			cursorPos -= 1;
		}
		blinkerCount = 0;
	}
	if (IsKeyDown(KEY_BACKSPACE)) {
		backSpaceCount += 1;
		blinkerCount = 0;
	}
	if (IsKeyReleased(KEY_BACKSPACE)) {
		backSpaceCount = 0;
	}
	if (IsKeyDown(KEY_BACKSPACE) && backSpaceCount > 20 && frameCount > 3) {
		if ((stringUpdate.length() > 0) && (cursorPos > 0)) {
			stringUpdate.erase(cursorPos-1, 1);
			cursorPos -= 1;
		}
		frameCount = 0;
	}

	
	if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_RIGHT)) {
		arrowKeyCount += 1;
		blinkerCount = 0;
	}
	if (IsKeyReleased(KEY_LEFT) || IsKeyReleased(KEY_RIGHT)) {
		arrowKeyCount = 0;
	}
	if (IsKeyPressed(KEY_LEFT) && (cursorPos > 0)) {
		cursorPos -= 1;
	}
	if ((IsKeyDown(KEY_LEFT) && (cursorPos > 0) && arrowKeyCount > 20 && frameCount > 3)){
		cursorPos -= 1;
		frameCount = 0;
	}
	if (IsKeyPressed(KEY_RIGHT) && cursorPos < stringUpdate.length()) {
		cursorPos += 1;
		blinkerCount = 0;
	}
	if ((IsKeyDown(KEY_RIGHT) && cursorPos < stringUpdate.length()) && arrowKeyCount > 20 && frameCount > 3) {
		cursorPos += 1;
		blinkerCount = 0;
		frameCount = 0;
	}

	buttonPress = "NULL";
	return stringUpdate;
}