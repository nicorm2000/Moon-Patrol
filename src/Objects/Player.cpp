#include "Objects/Player.h"

#include "raylib.h"

namespace game
{
	Player CreatePlayer(int screenWidth, int screenHeight)
	{
		float playerPosXDivider = 6.0f;
		float playerPosYDivider = 1.165f;

		Player player;

		player.pos.x = static_cast<float>(screenWidth / playerPosXDivider);
		player.pos.y = static_cast<float>(screenHeight / playerPosYDivider);

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
		int amountOfLifesLost = 1;

		if (play.isCollision == true)
		{
			play.lifes -= amountOfLifesLost;
		}
	}

	bool IsAlive(Player& play)
	{
		int minimumAmountOfLifes = 0;

		if (play.lifes <= minimumAmountOfLifes)
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
		int maximumAmountOfPoints = 15000000;

		if (play.points < maximumAmountOfPoints)
		{
			return play.win == true;
		}

		else
		{
			return play.win == false;
		}
	}
}