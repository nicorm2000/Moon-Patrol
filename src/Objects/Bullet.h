#pragma once
#include "raylib.h"

struct Bullet
{
	Vector2 pos;

	float height;
	float width;

	float speed;

	bool isMoving;
	bool isActive;

	Color color;

	static Texture bulletTexture;
};

Bullet CreateBullet();

void DrawBullet(Bullet& bullet);

void LoadTextureBullet(Bullet& bullet);

void UnloadTextureBullet(Bullet& bullet);