#pragma once
#include "raylib.h"

struct FlyEnemy
{
	Vector2 pos;
	
	float width;
	float height;

	float speed;

	bool moveDown;

	Color color;
};

FlyEnemy CreateFlyEnemy();

void DrawFlyEnemy(FlyEnemy& flyEnemy);