#include "Objects/Mouse.h"
#include "raylib.h"

namespace game
{
	Mouse CreateMouse()
	{
		Mouse mouse;

		mouse.position.x = 0;
		mouse.position.y = 0;

		mouse.width = 20.0f;
		mouse.height = 20.0f;

		return mouse;
	}

	Rectangle GetRecMouse(Mouse& mouse)
	{
		float mousePosDivider = 2.0f;

		return Rectangle{ mouse.position.x - mouse.width / mousePosDivider, mouse.position.y - mouse.height / mousePosDivider, mouse.width, mouse.height };
	}

	Vector2 CreateRecOriginMouse(Rectangle& mouseRec)
	{
		float mousePosDivider = 2.0f;

		Vector2 originRec;

		originRec.x = mouseRec.width / mousePosDivider - mouseRec.width / mousePosDivider;
		originRec.y = mouseRec.height / mousePosDivider - mouseRec.height / mousePosDivider;

		return originRec;
	}

	void DrawMouse(Mouse& mouse)
	{
		DrawTexture(mouse.mouseTexture, static_cast<int>(mouse.position.x), static_cast<int>(mouse.position.y), WHITE);
	}
}