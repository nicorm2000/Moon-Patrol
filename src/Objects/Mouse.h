#pragma once
#include "raylib.h"

namespace game
{
	struct Mouse
	{
		Vector2 position;

		Rectangle mouseRec;

		float width;

		float height;

		Texture2D texture;
	};

	Mouse CreateMouse();

	Rectangle GetRecMouse(Mouse& mouse);

	Vector2 CreateRecOriginMouse(Rectangle& mouseRec);

	void DrawMouse(Mouse& mouse, Rectangle& mouseRec);
}