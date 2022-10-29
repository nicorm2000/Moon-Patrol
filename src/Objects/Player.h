#pragma once
#include "raylib.h"

namespace game
{
	struct Player
	{
		Vector2 pos;

		float width;
		float height;

		float speed;

		Color color;
	};

	Player CreatePlayer(int screenWidth, int screenHeight);

	void DrawPlayer(Player& player);

	void PlayerLimit(Player& player, int screenWidth);
}