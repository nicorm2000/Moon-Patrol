#include <iostream>
#include "Objects/Obstacle.h"

using namespace std;

namespace game
{
	Obstacle CreateObstacle(int screenWidth, int screenHeight)
	{
		Obstacle obstacle;

		obstacle.pos.x = static_cast<float>(screenWidth - 30);
		obstacle.pos.y = static_cast<float>(screenHeight / 1.2f);

		obstacle.width = 60;
		obstacle.height = 120;

		obstacle.speed = 300;

		obstacle.color = WHITE;

		return obstacle;
	}

	void DrawObstacle(Obstacle& obstacle)
	{
		//DrawRectangle(static_cast<int>(obstacle.pos.x), static_cast<int>(obstacle.pos.y), static_cast<int>(obstacle.width), static_cast<int>(obstacle.height), obstacle.color);
		DrawTexture(obstacle.obstacleTexture, static_cast<int>(obstacle.pos.x), static_cast<int>(obstacle.pos.y), obstacle.color);
	}
}