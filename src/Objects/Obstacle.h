#pragma once
#include "raylib.h"
namespace game
{
	struct Obstacle
	{
		Vector2 pos;

		float width;
		float height;

		float speed;

		Color color;
		
		Texture obstacleTexture;
	};

	Obstacle CreateObstacle(int screenWidth, int screenHeight);

	void DrawObstacle(Obstacle& obstacle);
}