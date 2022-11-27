#include "Objects/Player.h"

#include "raylib.h"

namespace game
{
	Player CreatePlayer(int screenWidth, int screenHeight)
	{
		Player player;

		player.pos.x = static_cast<float>(screenWidth / 6);
		player.pos.y = static_cast<float>(screenHeight / 1.165);

		player.width = 80;
		player.height = 40;

		player.speed = 420;

		player.gravity = 0;

		player.jumpForce = 300;

		player.lifes = 1;

		player.points = 0;

		player.isJumping = false;
		player.isCollision = false;
		player.isAlive = true;
		player.win = false;

		player.color = WHITE;

		return player;
	}

	void DrawPlayer(Player& play)
	{
		//DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), static_cast<int>(player.width), static_cast<int>(player.height), player.color);
		DrawTexture(play.playerTexture, static_cast<int>(play.pos.x), static_cast<int>(play.pos.y), play.color);
	}

	void PlayerLimit(Player& play, int screenWidth)
	{
		if (play.pos.x > screenWidth - play.width)
		{
			play.pos.x = screenWidth - play.width;
		}

		if (play.pos.x < screenWidth / screenWidth)
		{
			play.pos.x = static_cast<float>(screenWidth / screenWidth);
		}
	}

	void LoseLife(Player& play)
	{
		if (play.isCollision == true)
		{
			play.lifes -= 1;
		}
	}

	bool IsAlive(Player& play)
	{
		if (play.lifes <= 0)
		{
			return play.isAlive == false;
		}

		else
		{
			return play.isAlive == true;
		}
	}

	bool PlayerWin(Player& play)
	{
		if (play.points < 15000000)
		{
			return play.win == true;
		}

		else
		{
			return play.win == false;
		}
	}
}