#include "raylib.h"
#include <iostream>
#include <string>
#include "UserInput.h""
#include "Evaluation.h"
using namespace std;
#define print(x) cout << x
/*
*
* TO-DO:
* Click to put cursor somewhere
* Add text to buttons
* 
*/

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

		//ROW0
		//DrawRectangleRounded({ 15, row1, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		//DrawRectangleRounded({ spacing * 3 + buttonWidth - 20, row1, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		//DrawRectangleRounded({ spacing * 9 + buttonWidth - 20, row1, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		//DrawRectangleRounded({ spacing * 15 + buttonWidth - 20, row1, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		//DrawRectangleRounded({ spacing * 21 + buttonWidth - 20, row1, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		//ROW1
		DrawRectangleRounded({ 15, row1, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		DrawRectangleRounded({ spacing * 3 + buttonWidth - 20, row1, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		DrawRectangleRounded({ spacing * 9 + buttonWidth - 20, row1, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		DrawRectangleRounded({ spacing * 15 + buttonWidth - 20, row1, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		DrawRectangleRounded({ spacing * 21 + buttonWidth - 20, row1, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		//ROW2
		DrawRectangleRounded({ 15, row2, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		DrawRectangleRounded({ spacing * 3 + buttonWidth - 20, row2, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		DrawRectangleRounded({ spacing * 9 + buttonWidth - 20, row2, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		DrawRectangleRounded({ spacing * 15 + buttonWidth - 20, row2, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		DrawRectangleRounded({ spacing * 21 + buttonWidth - 20, row2, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		//ROW3
		DrawRectangleRounded({ 15, row3, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		DrawRectangleRounded({ spacing * 3 + buttonWidth - 20, row3, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		DrawRectangleRounded({ spacing * 9 + buttonWidth - 20, row3, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		DrawRectangleRounded({ spacing * 15 + buttonWidth - 20, row3, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		DrawRectangleRounded({ spacing * 21 + buttonWidth - 20, row3, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		//ROW4
		DrawRectangleRounded({ 15, row4, buttonWidth *2 + spacing-8, buttonHeight }, 0.2f, 2, MAROON);
		DrawRectangleRounded({ spacing * 9 + buttonWidth - 20, row4, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		DrawRectangleRounded({ spacing * 15 + buttonWidth - 20, row4, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);
		DrawRectangleRounded({ spacing * 21 + buttonWidth - 20, row4, buttonWidth, buttonHeight }, 0.2f, 2, MAROON);

		if (IsKeyPressed(KEY_A)) {
			spacing -= 1.0f;
			print("\n" + to_string(spacing));
		}
		if (IsKeyPressed(KEY_S)) {
			spacing += 1.0f;
			print("\n" + to_string(spacing));
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
  0 , ., %, ^
*/