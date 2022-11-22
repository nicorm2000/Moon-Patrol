#pragma once
#include "Objects/Mouse.h"
#include "Objects/Player.h"
#include "raylib.h"

namespace game 
{
	struct MenuButton
	{
		Vector2 pos;

		float width;
		float height;

		int size;

		bool isActive;

		Texture texture;

		Color color;
	};

	enum class Menu
	{
		MainMenu,
		Play,
		Controls,
		Rules,
		Credits,
		Quit,
		PlayMenu
	};

	void InitMenu();
	void MenuCollisions(Mouse& mouse, int& optionSelect);
	void MenuInputs(Mouse& mouse, int& optionSelect, bool& playGame);
	void DrawMenu(Font gameFont);
	void DrawPlayMenu(Font gameFont, Player player, Player player2);
	void DrawControls(Font gameFont);
	void DrawRules(Font gameFont);
	void DrawCredits(Font gameFont);
}