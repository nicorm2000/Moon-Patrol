#include "Objects/Player.h"
namespace game
{
	Player CreatePlayer(int screenWidth, int screenHeight)
	{
		Player player;

		player.pos.x = static_cast<float>(screenWidth / 6);
		player.pos.y = static_cast<float>(screenHeight / 1.15);

		player.width = 80;
		player.height = 40;

		player.speed = 420;

		player.color = GREEN;

		return player;
	}

	void DrawPlayer(Player& player)
	{
		DrawRectangle(static_cast<int>(player.pos.x),
			static_cast<int>(player.pos.y),
			static_cast<int>(player.width),
			static_cast<int>(player.height), player.color);
	}

	void PlayerLimit(Player& player, int screenWidth)
	{
		if (player.pos.x > screenWidth - player.width)
		{
			player.pos.x = screenWidth - player.width;
		}

		if (player.pos.x < screenWidth / screenWidth)
		{
			player.pos.x = static_cast<float>(screenWidth / screenWidth);
		}
	}
}