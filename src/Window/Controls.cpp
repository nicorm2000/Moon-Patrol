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
}