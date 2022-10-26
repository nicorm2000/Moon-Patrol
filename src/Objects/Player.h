#pragma once
#include "raylib.h"

struct Player
{
	Vector2 pos;

	float width;
	float height;

	Color color;
};

Player CreatePlayer(int screenWidth, int screenHeight);