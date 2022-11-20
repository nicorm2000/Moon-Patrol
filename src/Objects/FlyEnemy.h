#pragma once
#include "raylib.h"

struct FlyEnemy
{
	Vector2 pos;
	
	float width;
	float height;

	float speed;

	int life;

	bool moveDown;
	bool isMoving;
	bool isActive;

	Color color;

	static Texture flyingEnemyTexture;
};

FlyEnemy CreateFlyEnemy();

void DrawFlyEnemy(FlyEnemy& flyEnemy);

//void LoadTextureFlyEnemy(FlyEnemy& flyEnemy);
//
//void UnloadTextureFlyEnemy(FlyEnemy& flyEnemy);