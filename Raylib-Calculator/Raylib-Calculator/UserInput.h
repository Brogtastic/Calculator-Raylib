#pragma once
#include <iostream>
#include <string>
#include "raylib.h"
#define print(x) cout << x
using namespace std;

extern int frameCount;
extern int backSpaceCount;
extern int arrowKeyCount;
extern int fontSize;
extern float pixelTextMinus;
extern int cursorPos;

extern string buttonPress;

string GetUserInput(string stringUpdate) {

	if ((IsKeyPressed(KEY_ZERO) && (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT))) || buttonPress == "close") {
		stringUpdate.insert(stringUpdate.length() + cursorPos + 1, ")");
	}
	else if (IsKeyPressed(KEY_ZERO) || buttonPress == "zero") {
		stringUpdate.insert(stringUpdate.length() + cursorPos + 1, "0");
	}
	if (IsKeyPressed(KEY_ONE) || buttonPress == "one") {
		stringUpdate.insert(stringUpdate.length() + cursorPos + 1, "1");
	}
	if (IsKeyPressed(KEY_TWO) || buttonPress == "two") {
		stringUpdate.insert(stringUpdate.length() + cursorPos + 1, "2");
	}
	if (IsKeyPressed(KEY_THREE) || buttonPress == "three") {
		stringUpdate.insert(stringUpdate.length() + cursorPos + 1, "3");
	}
	if (IsKeyPressed(KEY_FOUR) || buttonPress == "four") {
		stringUpdate.insert(stringUpdate.length() + cursorPos + 1, "4");
	}
	if (IsKeyPressed(KEY_FIVE) || buttonPress == "five") {
		stringUpdate.insert(stringUpdate.length() + cursorPos + 1, "5");
	}
	if ((IsKeyPressed(KEY_SIX) && (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT))) || buttonPress == "exponent") {
		stringUpdate.insert(stringUpdate.length() + cursorPos + 1, "^");
	}
	else if (IsKeyPressed(KEY_SIX) || buttonPress == "six") {
		stringUpdate.insert(stringUpdate.length() + cursorPos + 1, "6");
	}
	if (IsKeyPressed(KEY_SEVEN) || buttonPress == "seven") {
		stringUpdate.insert(stringUpdate.length() + cursorPos + 1, "7");
	}
	if ((IsKeyPressed(KEY_EIGHT) && (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT))) || buttonPress == "multiply")  {
		stringUpdate.insert(stringUpdate.length() + cursorPos + 1, "*");
	}
	else if (IsKeyPressed(KEY_EIGHT) || buttonPress == "eight") {
		stringUpdate.insert(stringUpdate.length() + cursorPos + 1, "8");
	}
	if ((IsKeyPressed(KEY_NINE) && (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT))) || buttonPress == "open") {
		stringUpdate.insert(stringUpdate.length() + cursorPos + 1, "(");
	}
	else if (IsKeyPressed(KEY_NINE) || buttonPress == "nine") {
		stringUpdate.insert(stringUpdate.length() + cursorPos + 1, "9");
	}
	if (IsKeyPressed(KEY_SPACE)) {
		stringUpdate.insert(stringUpdate.length() + cursorPos + 1, " ");
	}
	if ((IsKeyPressed(KEY_EQUAL) && (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT))) || buttonPress == "plus") {
		stringUpdate.insert(stringUpdate.length() + cursorPos + 1, "+");
	}
	if (IsKeyPressed(KEY_MINUS) || buttonPress == "minus") {
		stringUpdate.insert(stringUpdate.length() + cursorPos + 1, "-");
	}
	if (IsKeyPressed(KEY_SLASH) || buttonPress == "slash") {
		stringUpdate.insert(stringUpdate.length() + cursorPos + 1, "/");
	}
	if (IsKeyPressed(KEY_BACKSPACE)) {
		if ((stringUpdate.length() > 0) && (abs(cursorPos) <= stringUpdate.length())) {
			stringUpdate.erase(stringUpdate.length() + cursorPos, 1);
		}
	}
	if (IsKeyPressed(KEY_PERIOD) || buttonPress == "period") {
		stringUpdate.insert(stringUpdate.length() + cursorPos + 1, ".");
	}
	if (IsKeyDown(KEY_BACKSPACE)) {
		backSpaceCount += 1;
	}
	if (IsKeyReleased(KEY_BACKSPACE)) {
		backSpaceCount = 0;
	}
	if (IsKeyDown(KEY_BACKSPACE) && backSpaceCount > 20 && frameCount > 3) {
		if ((stringUpdate.length() > 0) && (abs(cursorPos) <= stringUpdate.length())) {
			stringUpdate.erase(stringUpdate.length() + cursorPos, 1);
		}
		frameCount = 0;
	}

	if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_RIGHT)) {
		arrowKeyCount += 1;
	}
	if (IsKeyReleased(KEY_LEFT) || IsKeyReleased(KEY_RIGHT)) {
		arrowKeyCount = 0;
	}
	if (IsKeyPressed(KEY_LEFT) && ((cursorPos > -1) || (stringUpdate.length() + cursorPos + 1 > 0))) {
		cursorPos -= 1;
		int place = stringUpdate.length() + cursorPos + 1;
		float more = 0.7f;
		if (stringUpdate[place] == '.') {
			pixelTextMinus += 0.2f * fontSize + more;
		}
		else if (stringUpdate[place] == '1') {
			pixelTextMinus += 0.3f * fontSize + more;
		}
		else if (stringUpdate[place] == '/') {
			pixelTextMinus += 0.8f * fontSize + more;
		}
		else if (stringUpdate[place] == '-') {
			pixelTextMinus += 0.5f * fontSize + more;
		}
		else if ((stringUpdate[place] == '(') || (stringUpdate[place] == ')') || (stringUpdate[place] == ' ') || stringUpdate[place] == '^') {
			pixelTextMinus += 0.4f * fontSize + more;
		}
		else {
			pixelTextMinus += 0.6f * fontSize + more;
		}
	}
	if ((IsKeyDown(KEY_LEFT) && ((cursorPos > -1) || (stringUpdate.length() + cursorPos + 1 > 0))) && arrowKeyCount > 20 && frameCount > 3) {
		cursorPos -= 1;
		int place = stringUpdate.length() + cursorPos + 1;
		float more = (2/3);
		if (stringUpdate[place] == '.') {
			pixelTextMinus += 0.2f * fontSize + more;
		}
		else if (stringUpdate[place] == '1') {
			pixelTextMinus += 0.3f * fontSize + more;
		}
		else if (stringUpdate[place] == '/') {
			pixelTextMinus += 0.8f * fontSize + more;
		}
		else if (stringUpdate[place] == '-') {
			pixelTextMinus += 0.5f * fontSize + more;
		}
		else if ((stringUpdate[place] == '(') || (stringUpdate[place] == ')') || (stringUpdate[place] == ' ') || stringUpdate[place] == '^') {
			pixelTextMinus += 0.4f * fontSize + more;
		}
		else {
			pixelTextMinus += 0.6f * fontSize + more;
		}
		frameCount = 0;
	}
	if (IsKeyPressed(KEY_RIGHT) && cursorPos < -1) {
		cursorPos += 1;
		int place = stringUpdate.length() + cursorPos;
		float more = 0.7f;
		if (stringUpdate[place] == '.') {
			pixelTextMinus -= 0.2f * fontSize + more;
		}
		else if (stringUpdate[place] == '1') {
			pixelTextMinus -= 0.3f * fontSize + more;
		}
		else if (stringUpdate[place] == '/') {
			pixelTextMinus -= 0.8f * fontSize + more;
		}
		else if (stringUpdate[place] == '-') {
			pixelTextMinus -= 0.5f * fontSize + more;
		}
		else if ((stringUpdate[place] == '(') || (stringUpdate[place] == ')') || (stringUpdate[place] == ' ') || stringUpdate[place] == '^') {
			pixelTextMinus -= 0.4f * fontSize + more;
		}
		else {
			pixelTextMinus -= 0.6f * fontSize + more;
		}
	}
	if ((IsKeyDown(KEY_RIGHT) && cursorPos < -1) && arrowKeyCount > 20 && frameCount > 3) {
		cursorPos += 1;
		int place = stringUpdate.length() + cursorPos;
		float more = 0.7f;
		if (stringUpdate[place] == '.') {
			pixelTextMinus -= 0.2f * fontSize + more;
		}
		else if (stringUpdate[place] == '1') {
			pixelTextMinus -= 0.3f * fontSize + more;
		}
		else if (stringUpdate[place] == '/') {
			pixelTextMinus -= 0.8f * fontSize + more;
		}
		else if (stringUpdate[place] == '-') {
			pixelTextMinus -= 0.5f * fontSize + more;
		}
		else if ((stringUpdate[place] == '(') || (stringUpdate[place] == ')') || (stringUpdate[place] == ' ') || stringUpdate[place] == '^') {
			pixelTextMinus -= 0.4f * fontSize + more;
		}
		else {
			pixelTextMinus -= 0.6f * fontSize + more;
		}
		frameCount = 0;
	}

	buttonPress = "NULL";
	return stringUpdate;
}