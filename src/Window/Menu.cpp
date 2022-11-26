#include "Window/Menu.h"
#include "Objects/Mouse.h"
#include "Objects/Player.h"

#include "raylib.h"

namespace game
{
	MenuButton play;
	MenuButton singlePlayer;
	MenuButton multiPlayer;
	MenuButton controls;
	MenuButton rules;
	MenuButton credits;
	MenuButton quit;
	MenuButton returnMenu;

	void InitMenu()
	{
		//Play Button

		play.pos.x = static_cast<float>(GetScreenWidth() / 20);
		play.pos.y = static_cast<float>(GetScreenHeight() / 3.5);
		play.width = static_cast<float>(GetScreenWidth() / 8);
		play.height = static_cast<float>(GetScreenHeight() / 16);
		play.size = 40;
		play.isActive = false;
		play.texture = LoadTexture("resources/Sprites/menuBg.png");

		play.color = BEIGE;

		//SinglePlayer Button

		singlePlayer.pos.x = static_cast<float>(GetScreenWidth() / 5.9);
		singlePlayer.pos.y = static_cast<float>(GetScreenHeight() / 1.5);
		singlePlayer.width = static_cast<float>(GetScreenWidth() / 5);
		singlePlayer.height = static_cast<float>(GetScreenHeight() / 16);
		singlePlayer.size = 40;
		singlePlayer.isActive = false;
		singlePlayer.texture = LoadTexture("resources/Sprites/Bg.png");

		singlePlayer.color = BEIGE;

		//MultiPlayer Button

		multiPlayer.pos.x = static_cast<float>(GetScreenWidth() / 1.55);
		multiPlayer.pos.y = static_cast<float>(GetScreenHeight() / 1.5);
		multiPlayer.width = static_cast<float>(GetScreenWidth() / 4);
		multiPlayer.height = static_cast<float>(GetScreenHeight() / 16);
		multiPlayer.size = 40;
		multiPlayer.isActive = false;

		multiPlayer.color = BEIGE;

		//Controls Button

		controls.pos.x = static_cast<float>(GetScreenWidth() / 20);
		controls.pos.y = static_cast<float>(GetScreenHeight() / 2.5);
		controls.width = static_cast<float>(GetScreenWidth() / 3.8);
		controls.height = static_cast<float>(GetScreenHeight() / 16);
		controls.size = 40;
		controls.isActive = false;
		controls.texture = LoadTexture("resources/Sprites/controlsBg.png");

		controls.color = BEIGE;

		//Rules Button

		rules.pos.x = static_cast<float>(GetScreenWidth() / 20);
		rules.pos.y = static_cast<float>(GetScreenHeight() / 1.93);
		rules.width = static_cast<float>(GetScreenWidth() / 6);
		rules.height = static_cast<float>(GetScreenHeight() / 16);
		rules.size = 40;
		rules.isActive = false;
		rules.texture = LoadTexture("resources/Sprites/rulesBg.png");

		rules.color = BEIGE;

		//Credits Button

		credits.pos.x = static_cast<float>(GetScreenWidth() / 1.5);
		credits.pos.y = static_cast<float>(GetScreenHeight() / 1.13);
		credits.width = static_cast<float>(GetScreenWidth() / 4.5);
		credits.height = static_cast<float>(GetScreenHeight() / 16);
		credits.size = 40;
		credits.isActive = false;
		credits.texture = LoadTexture("resources/Sprites/creditsBg.png");

		credits.color = BEIGE;

		//Quit Button

		quit.pos.x = static_cast<float>(GetScreenWidth() / 20);
		quit.pos.y = static_cast<float>(GetScreenHeight() / 1.59);
		quit.width = static_cast<float>(GetScreenWidth() / 8.2);
		quit.height = static_cast<float>(GetScreenHeight() / 16);
		quit.size = 40;
		quit.isActive = false;

		quit.color = BEIGE;

		//ReturnMenu Button

		returnMenu.pos.x = static_cast<float>(GetScreenWidth() / 2.1);
		returnMenu.pos.y = static_cast<float>(GetScreenHeight() / 1.1);
		returnMenu.width = static_cast<float>(GetScreenWidth() / 8);
		returnMenu.height = static_cast<float>(GetScreenHeight() / 16);
		returnMenu.size = 40;
		returnMenu.isActive = false;

		returnMenu.color = BEIGE;
	}

	void MenuCollisions(Mouse& mouse, int& optionSelect)
	{
		//Play Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 3.5), static_cast<float>(play.width), static_cast<float>(play.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
		{
			play.color = BLUE;
		}
		else
		{
			play.color = BEIGE;
		}

		//Controls Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 2.5), static_cast<float>(controls.width), static_cast<float>(controls.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
		{
			controls.color = BLUE;
		}
		else
		{
			controls.color = BEIGE;
		}

		//Rules Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 1.94), static_cast<float>(rules.width), static_cast<float>(rules.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
		{
			rules.color = BLUE;
		}
		else
		{
			rules.color = BEIGE;
		}

		//Credits Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 1.5), static_cast<float>(GetScreenHeight() / 1.13), static_cast<float>(credits.width), static_cast<float>(credits.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
		{
			credits.color = BLUE;
		}
		else
		{
			credits.color = BEIGE;
		}

		//Quit Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 1.59), static_cast<float>(quit.width), static_cast<float>(quit.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
		{
			quit.color = BLUE;
		}
		else
		{
			quit.color = BEIGE;
		}

		//ReturnMenu Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 2.1), static_cast<float>(GetScreenHeight() / 1.1), static_cast<float>(quit.width), static_cast<float>(quit.height) }) && optionSelect != 1)
		{
			returnMenu.color = BLUE;
		}
		else
		{
			returnMenu.color = BEIGE;
		}

		//SinglePlayer Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 6), static_cast<float>(GetScreenHeight() / 1.5), static_cast<float>(singlePlayer.width), static_cast<float>(singlePlayer.height) }))
		{
			singlePlayer.color = BLUE;
		}
		else
		{
			singlePlayer.color = BEIGE;
		}

		//MultiPlayer Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 1.55), static_cast<float>(GetScreenHeight() / 1.5), static_cast<float>(multiPlayer.width), static_cast<float>(multiPlayer.height) }))
		{
			multiPlayer.color = BLUE;
		}
		else
		{
			multiPlayer.color = BEIGE;
		}
	}

	void MenuInputs(Mouse& mouse, int& optionSelect, bool& playGame, bool& coop)
	{
		if (!playGame)
		{
			//Play Button
			if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 3.5), static_cast<float>(play.width), static_cast<float>(play.height) }))
			{
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
				{
					optionSelect = 6;
				}
			}

			//Controls Button
			if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 2.5), static_cast<float>(controls.width), static_cast<float>(controls.height) }))
			{
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
				{
					optionSelect = 2;
				}
			}

			//Rules Button
			if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 1.94), static_cast<float>(rules.width), static_cast<float>(rules.height) }))
			{
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
				{
					optionSelect = 3;
				}
			}

			//Credits Button
			if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 1.5), static_cast<float>(GetScreenHeight() / 1.13), static_cast<float>(credits.width), static_cast<float>(credits.height) }))
			{
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
				{
					optionSelect = 4;
				}
			}

			//Quit Button
			if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 1.59), static_cast<float>(quit.width), static_cast<float>(quit.height) }))
			{
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
				{
					optionSelect = 5;
				}
			}

			//ReturnMenu Button
			if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 2.1), static_cast<float>(GetScreenHeight() / 1.1), static_cast<float>(quit.width), static_cast<float>(quit.height) }))
			{
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1)
				{
					optionSelect = 0;
					playGame = false;
				}
			}

			//SinglePlayer Button
			if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 6), static_cast<float>(GetScreenHeight() / 1.5), static_cast<float>(singlePlayer.width), static_cast<float>(singlePlayer.height) }))
			{
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
				{
					optionSelect = 1;
					play.isActive = true;
					playGame = true;
					coop = false;
				}
			}
			
			//MultiPlayer Button
			if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 1.55), static_cast<float>(GetScreenHeight() / 1.5), static_cast<float>(multiPlayer.width), static_cast<float>(multiPlayer.height) }))
			{
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
				{
					optionSelect = 1;
					play.isActive = true;
					playGame = true;
					coop = true;
				}
			}
		}
	}

	void DrawMenu(Font gameFont)
	{
		ClearBackground(BLACK);

		DrawTexture(play.texture, 0, 0, WHITE);

		DrawTextEx(gameFont, "Cuteness", { static_cast<float>(GetScreenWidth() - 500) , static_cast<float>(GetScreenHeight() / 20) }, 100, 10, GOLD);
		DrawTextEx(gameFont, "Arises", { static_cast<float>(GetScreenWidth() - 350) , static_cast<float>(GetScreenHeight() / 5) }, 100, 10, GOLD);

		//Play Button

		DrawRectangle(static_cast<int>(GetScreenWidth() / 20), static_cast<int>(GetScreenHeight() / 3.5), static_cast<int>(play.width), static_cast<int>(play.height), BLANK);
		DrawTextEx(gameFont, "PLAY", play.pos, static_cast<float>(play.size), 10, play.color);

		//Controls Button

		DrawRectangle(static_cast<int>(GetScreenWidth() / 20), static_cast<int>(GetScreenHeight() / 2.5), static_cast<int>(controls.width), static_cast<int>(controls.height), BLANK);
		DrawTextEx(gameFont, "CONTROLS", controls.pos, static_cast<float>(controls.size), 10, controls.color);

		//Rules Button

		DrawRectangle(static_cast<int>(GetScreenWidth() / 20), static_cast<int>(GetScreenHeight() / 1.94), static_cast<int>(rules.width), static_cast<int>(rules.height), BLANK);
		DrawTextEx(gameFont, "RULES", rules.pos, static_cast<float>(rules.size), 10, rules.color);

		//Credits Button

		DrawRectangle(static_cast<int>(GetScreenWidth() / 1.5), static_cast<int>(GetScreenHeight() / 1.13), static_cast<int>(credits.width), static_cast<int>(credits.height), BLANK);
		DrawTextEx(gameFont, "CREDITS", credits.pos, static_cast<float>(credits.size), 10, credits.color);

		//Quit Button

		DrawRectangle(static_cast<int>(GetScreenWidth() / 20), static_cast<int>(GetScreenHeight() / 1.59), static_cast<int>(quit.width), static_cast<int>(quit.height), BLANK);
		DrawTextEx(gameFont, "QUIT", quit.pos, static_cast<float>(quit.size), 10, quit.color);
	}

	void DrawPlayMenu(Font gameFont, Player player, Player player2)
	{
		ClearBackground(BLACK);

		DrawTexture(singlePlayer.texture, 0, 0, WHITE);

		DrawTextEx(gameFont, "SinglePlayer", { static_cast<float>(GetScreenWidth() / 12) , static_cast<float>(GetScreenHeight() / 6) }, 60, 10, WHITE);
		DrawTextEx(gameFont, "MultiPlayer", { static_cast<float>(GetScreenWidth() / 1.7) , static_cast<float>(GetScreenHeight() / 6) }, 60, 10, WHITE);

		DrawTextureEx(player.playerTexture, { static_cast<float>(GetScreenWidth() / 6), static_cast<float>(GetScreenHeight() / 2.5) }, 0.0f, 2.0f, player.color);
		
		DrawTextureEx(player.playerTexture, { static_cast<float>(GetScreenWidth() / 1.55), static_cast<float>(GetScreenHeight() / 3.4) }, 0.0f, 2.0f, player.color);
		DrawTextureEx(player2.playerTexture, { static_cast<float>(GetScreenWidth() / 1.55), static_cast<float>(GetScreenHeight() / 2) }, 0.0f, 2.0f, player.color);

		DrawRectangle(static_cast<int>(GetScreenWidth() / 6), static_cast<int>(GetScreenHeight() / 1.5), static_cast<int>(singlePlayer.width), static_cast<int>(singlePlayer.height), BLANK);
		DrawTextEx(gameFont, "1 Player", singlePlayer.pos, static_cast<float>(singlePlayer.size), 10, singlePlayer.color);

		DrawRectangle(static_cast<int>(GetScreenWidth() / 1.55), static_cast<int>(GetScreenHeight() / 1.5), static_cast<int>(multiPlayer.width), static_cast<int>(multiPlayer.height), BLANK);
		DrawTextEx(gameFont, "2 Players", multiPlayer.pos, static_cast<float>(multiPlayer.size), 10, multiPlayer.color);

		//ReturnMenu Button

		DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), static_cast<int>(GetScreenHeight() / 1.1), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
		DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), 10, returnMenu.color);
	}

	void DrawControls(Font gameFont)
	{
		ClearBackground(BLACK);

		DrawTexture(controls.texture, 0, 0, WHITE);

		//ReturnMenu Button

		//DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), static_cast<int>(GetScreenHeight() / 1.1), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
		DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), 10, returnMenu.color);
	}

	void DrawRules(Font gameFont)
	{
		ClearBackground(BLACK);

		DrawTexture(rules.texture, 0, 0, WHITE);

		//ReturnMenu Button
		
		//DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), static_cast<int>(GetScreenHeight() / 1.1), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
		DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), 10, returnMenu.color);
	}

	void DrawCredits(Font gameFont)
	{
		ClearBackground(BLACK);

		DrawTexture(credits.texture, 0, 0, WHITE);

		//ReturnMenu Button
		//DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), static_cast<int>(GetScreenHeight() / 1.1), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
		DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), 10, returnMenu.color);
	}
}