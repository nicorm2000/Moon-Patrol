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

		float gravity;
		float jumpForce;

		int lifes;

		int points;

		bool isJumping;
		bool isCollision;
		bool isAlive;
		bool win;

		Color color;

		Texture playerTexture;
	};

	Player CreatePlayer(int screenWidth, int screenHeight);

	void DrawPlayer(Player& player);

	void PlayerLimit(Player& player, int screenWidth);

	void LoseLife(Player& player);

	bool IsAlive(Player& player);

	bool PlayerWin(Player& player);
}