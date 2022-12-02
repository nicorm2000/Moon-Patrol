#include "Window/MainMenu.h"
#include "Objects/Mouse.h"
#include "Objects/Player.h"

#include "raylib.h"

namespace game
{
	MenuButton rules1;

	void InitHowToPlay()
	{
		//Rules Button

		float rules1PosXDivider = 20.0f;
		float rules1PosYDivider = 1.93f;
		float rules1WidthDivider = 6.0f;
		float rules1HeightDivider = 16.0f;

		rules1.pos.x = static_cast<float>(GetScreenWidth() / rules1PosXDivider);
		rules1.pos.y = static_cast<float>(GetScreenHeight() / rules1PosYDivider);
		rules1.width = static_cast<float>(GetScreenWidth() / rules1WidthDivider);
		rules1.height = static_cast<float>(GetScreenHeight() / rules1HeightDivider);
		rules1.size = 40;
		rules1.isActive = false;
		rules1.texture = LoadTexture("resources/Sprites/rules1Bg.png");

		rules1.color = BEIGE;
	}

	void DrawRules1(Font gameFont)
	{
		gameFont;//ELIMINAR esto y sacar las dos barras ->//, los demas de 4 dejarlo en dos barras

		//ClearBackground(BLACK);

		//int menuPos = 0;

		//DrawTexture(rules.texture, menuPos, menuPos, WHITE);

		////ReturnMenu Button

		//float wordsSpacing = 10.0f;

		////DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), static_cast<int>(GetScreenHeight() / 1.1), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
		//DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), wordsSpacing, returnMenu.color);
	}
}