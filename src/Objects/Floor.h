#pragma once
#include "raylib.h"

namespace game
{
	struct Ground
	{
		Vector2 pos;

		float width;
		float height;

		Color color;
	};

	Ground CreateGround(int screenWidth, int screenHeight);
}