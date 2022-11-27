#include "Objects/Floor.h"
#include "raylib.h"

namespace game
{
	Ground CreateGround(int screenWidth, int screenHeight)
	{

		float groundPosXSubstraction = 1;
		float groundPosYDivider = 1.1f;

		Ground ground;

		ground.pos.x = static_cast<float>(screenWidth / screenWidth) - groundPosXSubstraction;
		ground.pos.y = static_cast<float>(screenHeight / groundPosYDivider);

		ground.width = static_cast<float>(screenWidth);
		ground.height = 70;

		ground.color = YELLOW;

		return ground;
	}
}