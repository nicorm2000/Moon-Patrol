#pragma once
#include "raylib.h"

namespace game
{
	struct Background
	{
		int posX;
		int posY;
		
		float width;
		float height;
		float scale;

		Texture tex;
	};

	Background CreateBackground(int screenWidth, int screenHeight, Texture tex);
	void DrawBackground(Texture tex, int& posX, int& posY);
}