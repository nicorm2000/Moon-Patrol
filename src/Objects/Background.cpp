#include "Objects/Background.h"

namespace game
{
	Background CreateBackground(int screenWidth, int screenHeight,Texture tex)
	{
		Background backG;

		backG.posX = screenWidth / screenWidth;
		backG.posY = screenHeight / screenHeight;

		backG.width = static_cast<float>(screenWidth);
		backG.height = static_cast<float>(screenHeight);

		backG.scale = 0.5;

		backG.tex = tex;

		return backG;
	}
	
	void DrawBackground(Texture tex, int& posX, int& posY)
	{
		DrawTexture(tex, posX, posY, WHITE);
	}
}