#pragma once
#include "raylib.h"

struct Player
{
	Vector2 pos;

	float width;
	float height;
};

Player CreatePlayer(int screenWidth, int screenHeight);