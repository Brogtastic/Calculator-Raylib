/*******************************************************************************************
*
*   raylib [core] example - Keyboard input
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2014-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <iostream>
#include <string>
#include "UserInput.h""
#include "Evaluation.h"
using namespace std;
#define print(x) cout << x

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

int frameCount = 0;
int backSpaceCount = 0;
int arrowKeyCount = 0;
int fontSize = 40;
float pixelTextMinus = 0;
int cursorPos = -1;

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 576;
	const int screenHeight = 700;

	InitWindow(screenWidth, screenHeight, "raylib calculator");

	Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };
	Vector2 targetPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };

	string myString = "";
	string meh = "";
	const char * resultsText = myString.c_str();
	const char * calculationsText;
	const char * typeline;

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------

		frameCount += 1;
		if (frameCount > 60) frameCount = 0;
		myString = GetUserInput(myString);

		if (IsKeyPressed(KEY_ENTER)) {
			meh = EvaluateExpression(myString);
			print(EvaluateExpression(myString));
		}

		Vector2 mousePosition = GetMousePosition();

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			print("\n\nMOUSE X: " + to_string(mousePosition.x));
			print("MOUSE Y: " + to_string(mousePosition.y) + "\n");
		}

		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		calculationsText = myString.c_str();
		resultsText = meh.c_str();
		typeline = "|";

		int pixelTextLength = 0;

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
		}

		pixelTextLength -= pixelTextMinus;

		DrawText(calculationsText, 10, 10, fontSize, DARKGRAY);

		DrawText(resultsText, 10, 60, 30, DARKGRAY);

		if (frameCount < 30) {
			DrawText(typeline, 12 + pixelTextLength, 10, fontSize, DARKGRAY);
		}

		DrawRectangle(45, 175, 160, 120, BLUE);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}