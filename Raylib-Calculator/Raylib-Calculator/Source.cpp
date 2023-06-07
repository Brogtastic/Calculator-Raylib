#include "raylib.h"
#include <iostream>
#include <string>
#include "UserInput.h""
#include "Evaluation.h"
#include <list>
#define GetIntArrayLength(x) sizeof(x) / sizeof(int)
using namespace std;
#define print(x) cout << x
/*
*
* TO-DO:
* Click to put cursor somewhere
* Big integer result?
*/

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

int frameCount = 0;
int blinkerCount = 0;
int backSpaceCount = 0;
int arrowKeyCount = 0;
int fontSize = 40;
int buttonFontSize = 60;
float pixelTextMinus = 0;
int cursorPos = 0;

list<int> cursorCorX;
list<int> cursorCorY;

string buttonPress = "None";

CLITERAL(Color) numButtonColor { 190, 33, 55, 255 }; // MAROON
CLITERAL(Color) numButtonColorHighlight { 224, 66, 87, 255 }; // MAROON HIGHLIGHT
CLITERAL(Color) numButtonColorPressed { 164, 36, 53, 255 }; // MAROON PRESS

CLITERAL(Color) operatorButtonColor { 214, 46, 26, 255 }; // ORANGE-Y
CLITERAL(Color) operatorColorHighlight { 240, 84, 66, 255 }; // ORANGE-Y HIGHLIGHT
CLITERAL(Color) operatorColorPressed { 189, 33, 15, 255 }; // ORANGE-Y PRESS

CLITERAL(Color) numTextColor { 200, 200, 200, 255 };
CLITERAL(Color) operatorTextColor { 165, 165, 165, 255 };

CLITERAL(Color) button1Color = numButtonColor;
CLITERAL(Color) button2Color = numButtonColor;
CLITERAL(Color) button3Color = numButtonColor;
CLITERAL(Color) buttonPlusColor = operatorButtonColor;
CLITERAL(Color) buttonMinusColor = operatorButtonColor;

CLITERAL(Color) button4Color = numButtonColor;
CLITERAL(Color) button5Color = numButtonColor;
CLITERAL(Color) button6Color = numButtonColor;
CLITERAL(Color) buttonMultiplyColor = operatorButtonColor;
CLITERAL(Color) buttonDivideColor = operatorButtonColor;

CLITERAL(Color) button7Color = numButtonColor;
CLITERAL(Color) button8Color = numButtonColor;
CLITERAL(Color) button9Color = numButtonColor;
CLITERAL(Color) buttonOpenPColor = operatorButtonColor;
CLITERAL(Color) buttonClosePColor = operatorButtonColor;

CLITERAL(Color) button0Color = numButtonColor;
CLITERAL(Color) buttonPeriodColor = operatorButtonColor;
CLITERAL(Color) buttonExponentColor = operatorButtonColor;
CLITERAL(Color) buttonEqualsColor = operatorButtonColor;



CLITERAL(Color) backgroundColor { 212, 192, 190, 255 }; // Background color

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 475;
	const int screenHeight = 635;

	InitWindow(screenWidth, screenHeight, "raylib calculator");

	Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };
	Vector2 targetPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };

	string myString = "";
	string meh = "";
	const char * resultsText = myString.c_str();
	const char * calculationsText;
	const char * typeline;

	float buttonWidth = 80.0f;
	float buttonHeight = 100.0f;
	float row1 = 175.0f;
	float spacing = 15.0f;
	float row2 = buttonHeight + row1 + spacing;
	float row3 = buttonHeight + row2 + spacing;
	float row4 = buttonHeight + row3 + spacing;
	float row5 = buttonHeight + row4 + spacing;


	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------

		Rectangle mousePos = { GetMousePosition().x, GetMousePosition().y, 2, 2};

		frameCount += 1;
		if (frameCount > 60) frameCount = 0;

		blinkerCount += 1;
		if (blinkerCount > 60) blinkerCount = 0;

		if (IsKeyPressed(KEY_ENTER) || buttonPress == "equals") {
			meh = EvaluateExpression(myString);
			print(EvaluateExpression(myString));
		}
		myString = GetUserInput(myString);


		Vector2 mousePosition = GetMousePosition();

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			print("\n\nMOUSE X: " + to_string(mousePosition.x));
			print("MOUSE Y: " + to_string(mousePosition.y) + "\n");
		}

		if (IsKeyPressed(KEY_G)) {
			print("\n\nCURSOR COR X: ");
			for (const auto& element : cursorCorX) {
				std::cout << element << " ";
			}
			print("\nCURSOR COR Y: ");
			for (const auto& element : cursorCorY) {
				std::cout << element << " ";
			}
		}

		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(backgroundColor);

		calculationsText = myString.c_str();
		resultsText = meh.c_str();
		typeline = "|";

		int pixelTextLength = 0;
		cursorCorX.clear();
		cursorCorY.clear();
		cursorCorX.push_back(12);
		cursorCorY.push_back(10);

		for (int i = 0; i < myString.length(); i++) {
			if (myString[i] == '.') {
				pixelTextLength += 0.2f * fontSize;
			}
			else if (myString[i] == '1') {
				pixelTextLength += 0.3f * fontSize;
			}
			else if (myString[i] == '/') {
				pixelTextLength += 0.8f * fontSize;
			}
			else if (myString[i] == '-') {
				pixelTextLength += 0.5f * fontSize;
			}
			else if ((myString[i] == '(') || (myString[i] == ')') || (myString[i] == ' ') || myString[i] == '^') {
				pixelTextLength += 0.4f * fontSize;
			}
			else {
				pixelTextLength += 0.6f * fontSize;
			}
			cursorCorX.push_back(12 + pixelTextLength);
			cursorCorY.push_back(10);
		}

		pixelTextLength -= pixelTextMinus;

		DrawText(calculationsText, 10, 10, fontSize, DARKGRAY);

		DrawText(resultsText, 10, 60, 30, DARKGRAY);

		if (blinkerCount < 30) {
			//DrawText(typeline, 12 + pixelTextLength, 10, fontSize, DARKGRAY);
			std::list<int>::iterator xPlacement = std::next(cursorCorX.begin(), cursorPos);
			int cursorPlacement = *xPlacement;

			if (cursorPos == myString.length()) {
				DrawText(typeline, cursorPlacement, 10, fontSize, DARKGRAY);
			}
			else {
				DrawText(typeline, cursorPlacement-5, 10, fontSize, DARKGRAY);
			}
		}

		//ROW1 (1   2    3   +   -)
		Rectangle key1 = { 15, row1, buttonWidth, buttonHeight };
		Rectangle key2 = { spacing * 3 + buttonWidth - 20, row1, buttonWidth, buttonHeight };
		Rectangle key3 = { spacing * 9 + buttonWidth - 20, row1, buttonWidth, buttonHeight };
		Rectangle keyPlus = { spacing * 15 + buttonWidth - 20, row1, buttonWidth, buttonHeight };
		Rectangle keyMinus = { spacing * 21 + buttonWidth - 20, row1, buttonWidth, buttonHeight };

		//ROW2 (4   5   6   *   /)
		Rectangle key4 = { 15, row2, buttonWidth, buttonHeight };
		Rectangle key5 = { spacing * 3 + buttonWidth - 20, row2, buttonWidth, buttonHeight };
		Rectangle key6 = { spacing * 9 + buttonWidth - 20, row2, buttonWidth, buttonHeight };
		Rectangle keyMultiply = { spacing * 15 + buttonWidth - 20, row2, buttonWidth, buttonHeight };
		Rectangle keyDivide = { spacing * 21 + buttonWidth - 20, row2, buttonWidth, buttonHeight };

		//ROW3 (7   8   9   (   ))
		Rectangle key7 = { 15, row3, buttonWidth, buttonHeight };
		Rectangle key8 = { spacing * 3 + buttonWidth - 20, row3, buttonWidth, buttonHeight };
		Rectangle key9 = { spacing * 9 + buttonWidth - 20, row3, buttonWidth, buttonHeight };
		Rectangle keyOpenP = { spacing * 15 + buttonWidth - 20, row3, buttonWidth, buttonHeight };
		Rectangle keyCloseP = { spacing * 21 + buttonWidth - 20, row3, buttonWidth, buttonHeight };

		//ROW4 (   0    .   %   ^)
		Rectangle key0 = { 15, row4, buttonWidth * 2 + 10, buttonHeight };
		Rectangle keyPeriod = { spacing * 9 + buttonWidth - 20, row4, buttonWidth, buttonHeight };
		Rectangle keyExponent = { spacing * 15 + buttonWidth - 20, row4, buttonWidth, buttonHeight };
		Rectangle keyEquals = { spacing * 21 + buttonWidth - 20, row4, buttonWidth, buttonHeight };


		DrawRectangleRounded(key1, 0.2f, 2, button1Color);
		DrawText("1", 15 + 32, row1 + 22, buttonFontSize, numTextColor);
		DrawRectangleRounded(key2, 0.2f, 2, button2Color);
		DrawText("2", 15 + buttonWidth + 36, row1 + 22, buttonFontSize, numTextColor);
		DrawRectangleRounded(key3, 0.2f, 2, button3Color);
		DrawText("3", 15 + buttonWidth*2 + 46, row1 + 22, buttonFontSize, numTextColor);
		DrawRectangleRounded(keyPlus, 0.2f, 2, buttonPlusColor);
		DrawText("+", 30 + buttonWidth * 3 + 41, row1 + 22, buttonFontSize, operatorTextColor);
		DrawRectangleRounded(keyMinus, 0.2f, 2, buttonMinusColor);
		DrawText("-", 45 + buttonWidth * 4 + 39, row1 + 22, buttonFontSize, operatorTextColor);

		DrawRectangleRounded(key4, 0.2f, 2, button4Color);
		DrawText("4", 15 + 26, row2 + 22, buttonFontSize, numTextColor);
		DrawRectangleRounded(key5, 0.2f, 2, button5Color);
		DrawText("5", 15 + buttonWidth + 36, row2 + 22, buttonFontSize, numTextColor);
		DrawRectangleRounded(key6, 0.2f, 2, button6Color);
		DrawText("6", 15 + buttonWidth * 2 + 46, row2 + 22, buttonFontSize, numTextColor);
		DrawRectangleRounded(keyMultiply, 0.2f, 2, buttonMultiplyColor);
		DrawText("*", 30 + buttonWidth * 3 + 40, row2 + 22, buttonFontSize, operatorTextColor);
		DrawRectangleRounded(keyDivide, 0.2f, 2, buttonDivideColor);
		DrawText("/", 45 + buttonWidth * 4 + 30, row2 + 22, buttonFontSize, operatorTextColor);

		DrawRectangleRounded(key7, 0.2f, 2, button7Color);
		DrawText("7", 15 + 26, row3 + 22, buttonFontSize, numTextColor);
		DrawRectangleRounded(key8, 0.2f, 2, button8Color);
		DrawText("8", 15 + buttonWidth + 36, row3 + 22, buttonFontSize, numTextColor);
		DrawRectangleRounded(key9, 0.2f, 2, button9Color);
		DrawText("9", 15 + buttonWidth * 2 + 46, row3 + 22, buttonFontSize, numTextColor);
		DrawRectangleRounded(keyOpenP, 0.2f, 2, buttonOpenPColor);
		DrawText("(", 30 + buttonWidth * 3 + 42, row3 + 22, buttonFontSize, operatorTextColor);
		DrawRectangleRounded(keyCloseP, 0.2f, 2, buttonClosePColor);
		DrawText(")", 45 + buttonWidth * 4 + 41, row3 + 22, buttonFontSize, operatorTextColor);

		DrawRectangleRounded(key0, 0.2f, 2, button0Color);
		DrawText("0", 15 + 26, row4 + 22, buttonFontSize, numTextColor);
		DrawRectangleRounded(keyPeriod, 0.2f, 2, buttonPeriodColor);
		DrawText(".", 15 + buttonWidth * 2 + 57, row4 + 22, buttonFontSize, operatorTextColor);
		DrawRectangleRounded(keyExponent, 0.2f, 2, buttonExponentColor);
		DrawText("^", 30 + buttonWidth * 3 + 47, row4 + 22, buttonFontSize, operatorTextColor);
		DrawRectangleRounded(keyEquals, 0.2f, 2, buttonEqualsColor);
		DrawText("=", 45 + buttonWidth * 4 + 39, row4 + 22, buttonFontSize, operatorTextColor);

		if (CheckCollisionRecs(key1, mousePos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			buttonPress = "one";
		}
		else if (CheckCollisionRecs(key1, mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			button1Color = numButtonColorPressed;
		}
		else if (CheckCollisionRecs(key1, mousePos)) {
			button1Color = numButtonColorHighlight;
		}
		else {
			button1Color = numButtonColor;
		}

		if (CheckCollisionRecs(key2, mousePos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			buttonPress = "two";
		}
		else if (CheckCollisionRecs(key2, mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			button2Color = numButtonColorPressed;
		}
		else if (CheckCollisionRecs(key2, mousePos)) {
			button2Color = numButtonColorHighlight;
		}
		else {
			button2Color = numButtonColor;
		}

		if (CheckCollisionRecs(key3, mousePos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			buttonPress = "three";
		}
		else if (CheckCollisionRecs(key3, mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			button3Color = numButtonColorPressed;
		}
		else if (CheckCollisionRecs(key3, mousePos)) {
			button3Color = numButtonColorHighlight;
		}
		else {
			button3Color = numButtonColor;
		}

		if (CheckCollisionRecs(key4, mousePos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			buttonPress = "four";
		}
		else if (CheckCollisionRecs(key4, mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			button4Color = numButtonColorPressed;
		}
		else if (CheckCollisionRecs(key4, mousePos)) {
			button4Color = numButtonColorHighlight;
		}
		else {
			button4Color = numButtonColor;
		}

		if (CheckCollisionRecs(key5, mousePos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			buttonPress = "five";
		}
		else if (CheckCollisionRecs(key5, mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			button5Color = numButtonColorPressed;
		}
		else if (CheckCollisionRecs(key5, mousePos)) {
			button5Color = numButtonColorHighlight;
		}
		else {
			button5Color = numButtonColor;
		}

		if (CheckCollisionRecs(key6, mousePos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			buttonPress = "six";
		}
		else if (CheckCollisionRecs(key6, mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			button6Color = numButtonColorPressed;
		}
		else if (CheckCollisionRecs(key6, mousePos)) {
			button6Color = numButtonColorHighlight;
		}
		else {
			button6Color = numButtonColor;
		}

		if (CheckCollisionRecs(key7, mousePos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			buttonPress = "seven";
		}
		else if (CheckCollisionRecs(key7, mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			button7Color = numButtonColorPressed;
		}
		else if (CheckCollisionRecs(key7, mousePos)) {
			button7Color = numButtonColorHighlight;
		}
		else {
			button7Color = numButtonColor;
		}

		if (CheckCollisionRecs(key8, mousePos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			buttonPress = "eight";
		}
		else if (CheckCollisionRecs(key8, mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			button8Color = numButtonColorPressed;
		}
		else if (CheckCollisionRecs(key8, mousePos)) {
			button8Color = numButtonColorHighlight;
		}
		else {
			button8Color = numButtonColor;
		}

		if (CheckCollisionRecs(key9, mousePos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			buttonPress = "nine";
		}
		else if (CheckCollisionRecs(key9, mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			button9Color = numButtonColorPressed;
		}
		else if (CheckCollisionRecs(key9, mousePos)) {
			button9Color = numButtonColorHighlight;
		}
		else {
			button9Color = numButtonColor;
		}

		if (CheckCollisionRecs(key0, mousePos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			buttonPress = "zero";
		}
		else if (CheckCollisionRecs(key0, mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			button0Color = numButtonColorPressed;
		}
		else if (CheckCollisionRecs(key0, mousePos)) {
			button0Color = numButtonColorHighlight;
		}
		else {
			button0Color = numButtonColor;
		}

		if (CheckCollisionRecs(keyPlus, mousePos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			buttonPress = "plus";
		}
		else if (CheckCollisionRecs(keyPlus, mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			buttonPlusColor = operatorColorPressed;
		}
		else if (CheckCollisionRecs(keyPlus, mousePos)) {
			buttonPlusColor = operatorColorHighlight;
		}
		else {
			buttonPlusColor = operatorButtonColor;
		}

		if (CheckCollisionRecs(keyMinus, mousePos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			buttonPress = "minus";
		}
		else if (CheckCollisionRecs(keyMinus, mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			buttonMinusColor = operatorColorPressed;
		}
		else if (CheckCollisionRecs(keyMinus, mousePos)) {
			buttonMinusColor = operatorColorHighlight;
		}
		else {
			buttonMinusColor = operatorButtonColor;
		}

		if (CheckCollisionRecs(keyMultiply, mousePos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			buttonPress = "multiply";
		}
		else if (CheckCollisionRecs(keyMultiply, mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			buttonMultiplyColor = operatorColorPressed;
		}
		else if (CheckCollisionRecs(keyMultiply, mousePos)) {
			buttonMultiplyColor = operatorColorHighlight;
		}
		else {
			buttonMultiplyColor = operatorButtonColor;
		}

		if (CheckCollisionRecs(keyDivide, mousePos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			buttonPress = "slash";
		}
		else if (CheckCollisionRecs(keyDivide, mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			buttonDivideColor = operatorColorPressed;
		}
		else if (CheckCollisionRecs(keyDivide, mousePos)) {
			buttonDivideColor = operatorColorHighlight;
		}
		else {
			buttonDivideColor = operatorButtonColor;
		}

		if (CheckCollisionRecs(keyOpenP, mousePos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			buttonPress = "open";
		}
		else if (CheckCollisionRecs(keyOpenP, mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			buttonOpenPColor = operatorColorPressed;
		}
		else if (CheckCollisionRecs(keyOpenP, mousePos)) {
			buttonOpenPColor = operatorColorHighlight;
		}
		else {
			buttonOpenPColor = operatorButtonColor;
		}

		if (CheckCollisionRecs(keyCloseP, mousePos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			buttonPress = "close";
		}
		else if (CheckCollisionRecs(keyCloseP, mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			buttonClosePColor = operatorColorPressed;
		}
		else if (CheckCollisionRecs(keyCloseP, mousePos)) {
			buttonClosePColor = operatorColorHighlight;
		}
		else {
			buttonClosePColor = operatorButtonColor;
		}

		if (CheckCollisionRecs(keyPeriod, mousePos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			buttonPress = "period";
		}
		else if (CheckCollisionRecs(keyPeriod, mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			buttonPeriodColor = operatorColorPressed;
		}
		else if (CheckCollisionRecs(keyPeriod, mousePos)) {
			buttonPeriodColor = operatorColorHighlight;
		}
		else {
			buttonPeriodColor = operatorButtonColor;
		}

		if (CheckCollisionRecs(keyExponent, mousePos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			buttonPress = "exponent";
		}
		else if (CheckCollisionRecs(keyExponent, mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			buttonExponentColor = operatorColorPressed;
		}
		else if (CheckCollisionRecs(keyExponent, mousePos)) {
			buttonExponentColor = operatorColorHighlight;
		}
		else {
			buttonExponentColor = operatorButtonColor;
		}

		if (CheckCollisionRecs(keyEquals, mousePos) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			buttonPress = "equals";
		}
		else if (CheckCollisionRecs(keyEquals, mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			buttonEqualsColor = operatorColorPressed;
		}
		else if (CheckCollisionRecs(keyEquals, mousePos)) {
			buttonEqualsColor = operatorColorHighlight;
		}
		else {
			buttonEqualsColor = operatorButtonColor;
		}


		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}

/*
Arrows, A/C
1, 2, 3, + , -
4, 5, 6, * , /
7, 8, 9, ( , )
  0 , ., ^, =
*/