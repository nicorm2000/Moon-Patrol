#include "Window/MainMenu.h"
#include "Objects/Mouse.h"
#include "Objects/Player.h"

#include "raylib.h"

namespace game
{
	MenuButton credits1;

	void InitCredits()
	{
		//Credits Button

		float credits1PosXDivider = 1.5f;
		float credits1PosYDivider = 1.13f;
		float credits1WidthDivider = 4.5f;
		float credits1HeightDivider = 16.0f;

		credits1.pos.x = static_cast<float>(GetScreenWidth() / credits1PosXDivider);
		credits1.pos.y = static_cast<float>(GetScreenHeight() / credits1PosYDivider);
		credits1.width = static_cast<float>(GetScreenWidth() / credits1WidthDivider);
		credits1.height = static_cast<float>(GetScreenHeight() / credits1HeightDivider);
		credits1.size = 40;
		credits1.isActive = false;
		credits1.texture = LoadTexture("resources/Sprites/credits1Bg.png");

		credits1.color = BEIGE;
	}
}