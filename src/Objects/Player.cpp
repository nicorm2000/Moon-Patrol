#include "Objects/Player.h"

Player CreatePlayer(int screenWidth, int screenHeight)
{
	Player player;

	player.pos.x = static_cast<float>(screenWidth / 6);
	player.pos.y = static_cast<float>(screenHeight / 1.2);

	player.width = 80;
	player.height = 40;

	player.color = RED;

	return player;
}