#include "Objects/Floor.h"
#include "raylib.h"

namespace game
{
	Ground CreateGround(int screenWidth, int screenHeight)
	{
		Ground ground;

		ground.pos.x = static_cast<float>(screenWidth / screenWidth) -1;
		ground.pos.y = static_cast<float>(screenHeight / 1.1);

		ground.width = static_cast<float>(screenWidth);
		ground.height = 70;

		ground.color = YELLOW;

		return ground;
	}
}