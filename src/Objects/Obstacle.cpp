#include <iostream>
#include "Objects/Obstacle.h"

using namespace std;

namespace game
{
	Obstacle CreateObstacle(int screenWidth, int screenHeight)
	{
		Obstacle obstacle;

		obstacle.pos.x = static_cast<float>(screenWidth - 30);
		obstacle.pos.y = static_cast<float>(screenHeight / 1.2);

		obstacle.width = 30;
		obstacle.height = 60;

		obstacle.speed = 400;

		obstacle.color = BLUE;

		return obstacle;
	}

	void DrawObstacle(Obstacle& obstacle)
	{
		DrawRectangle(static_cast<int>(obstacle.pos.x),
			static_cast<int>(obstacle.pos.y),
			static_cast<int>(obstacle.width),
			static_cast<int>(obstacle.height), obstacle.color);
	}

	void ObstacleTeleport(Obstacle& obstacle, int screenWidth)
	{
		if (obstacle.pos.x > screenWidth - obstacle.width)
		{
			obstacle.pos.x = static_cast<float>(screenWidth / screenWidth);
		}

		if (obstacle.pos.x < screenWidth / screenWidth - obstacle.width)
		{
			cout << "Ganaste" << endl;
			obstacle.pos.x = screenWidth - obstacle.width;
		}
	}
}