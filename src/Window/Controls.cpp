#include "Window/MainMenu.h"
#include "Objects/Mouse.h"
#include "Objects/Player.h"

#include "raylib.h"

namespace game
{
	MenuButton controls1;

	void InitControls()
	{
		//Controls Button

		float controls1PosXDivider = 20.0f;
		float controls1PosYDivider = 2.5f;
		float controls1WidthDivider = 3.8f;
		float controls1HeightDivider = 16.0f;

		controls1.pos.x = static_cast<float>(GetScreenWidth() / controls1PosXDivider);
		controls1.pos.y = static_cast<float>(GetScreenHeight() / controls1PosYDivider);
		controls1.width = static_cast<float>(GetScreenWidth() / controls1WidthDivider);
		controls1.height = static_cast<float>(GetScreenHeight() / controls1HeightDivider);
		controls1.size = 40;
		controls1.isActive = false;
		controls1.texture = LoadTexture("resources/Sprites/controls1Bg.png");

		controls1.color = BEIGE;
	}

	void DrawControls1(Font gameFont)
	{
		gameFont;//ELIMINAR esto y sacar las dos barras ->//, los demas de 4 dejarlo en dos barras
		//ClearBackground(BLACK);

		//int menuPos = 0;

		//DrawTexture(controls1.texture, menuPos, menuPos, WHITE);

		////ReturnMenu Button

		////float wordsSpacing = 10.0f;

		////DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), static_cast<int>(GetScreenHeight() / 1.1), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
		//DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), wordsSpacing, returnMenu.color);
	}
}