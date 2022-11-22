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
		play.width = static_cast<float>(GetScreenWidth() / 13);
		play.height = static_cast<float>(GetScreenHeight() / 16);
		play.size = 40;
		play.isActive = false;

		play.color = ORANGE;

		//SinglePlayer Button

		singlePlayer.pos.x = static_cast<float>(GetScreenWidth() / 5.9);
		singlePlayer.pos.y = static_cast<float>(GetScreenHeight() / 1.5);
		singlePlayer.width = static_cast<float>(GetScreenWidth() / 7);
		singlePlayer.height = static_cast<float>(GetScreenHeight() / 16);
		singlePlayer.size = 40;
		singlePlayer.isActive = false;

		singlePlayer.color = ORANGE;

		//MultiPlayer Button

		multiPlayer.pos.x = static_cast<float>(GetScreenWidth() / 1.55);
		multiPlayer.pos.y = static_cast<float>(GetScreenHeight() / 1.5);
		multiPlayer.width = static_cast<float>(GetScreenWidth() / 6);
		multiPlayer.height = static_cast<float>(GetScreenHeight() / 16);
		multiPlayer.size = 40;
		multiPlayer.isActive = false;

		multiPlayer.color = ORANGE;

		//Controls Button

		controls.pos.x = static_cast<float>(GetScreenWidth() / 20);
		controls.pos.y = static_cast<float>(GetScreenHeight() / 2.5);
		controls.width = static_cast<float>(GetScreenWidth() / 6.4);
		controls.height = static_cast<float>(GetScreenHeight() / 16);
		controls.size = 40;
		controls.isActive = false;

		controls.color = ORANGE;

		//Rules Button

		rules.pos.x = static_cast<float>(GetScreenWidth() / 20);
		rules.pos.y = static_cast<float>(GetScreenHeight() / 1.93);
		rules.width = static_cast<float>(GetScreenWidth() / 10.3);
		rules.height = static_cast<float>(GetScreenHeight() / 16);
		rules.size = 40;
		rules.isActive = false;

		rules.color = ORANGE;

		//Credits Button

		credits.pos.x = static_cast<float>(GetScreenWidth() / 1.5);
		credits.pos.y = static_cast<float>(GetScreenHeight() / 1.13);
		credits.width = static_cast<float>(GetScreenWidth() / 7.3);
		credits.height = static_cast<float>(GetScreenHeight() / 16);
		credits.size = 40;
		credits.isActive = false;

		credits.color = ORANGE;

		//Quit Button

		quit.pos.x = static_cast<float>(GetScreenWidth() / 20);
		quit.pos.y = static_cast<float>(GetScreenHeight() / 1.59);
		quit.width = static_cast<float>(GetScreenWidth() / 13);
		quit.height = static_cast<float>(GetScreenHeight() / 16);
		quit.size = 40;
		quit.isActive = false;

		quit.color = ORANGE;

		//ReturnMenu Button

		returnMenu.pos.x = static_cast<float>(GetScreenWidth() / 2.17);
		returnMenu.pos.y = static_cast<float>(GetScreenHeight() / 1.1);
		returnMenu.width = static_cast<float>(GetScreenWidth() / 10);
		returnMenu.height = static_cast<float>(GetScreenHeight() / 16);
		returnMenu.size = 40;
		returnMenu.isActive = false;

		returnMenu.color = ORANGE;
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
			play.color = ORANGE;
		}

		//Controls Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 2.5), static_cast<float>(controls.width), static_cast<float>(controls.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
		{
			controls.color = BLUE;
		}
		else
		{
			controls.color = ORANGE;
		}

		//Rules Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 1.94), static_cast<float>(rules.width), static_cast<float>(rules.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
		{
			rules.color = BLUE;
		}
		else
		{
			rules.color = ORANGE;
		}

		//Credits Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 1.5), static_cast<float>(GetScreenHeight() / 1.13), static_cast<float>(credits.width), static_cast<float>(credits.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
		{
			credits.color = BLUE;
		}
		else
		{
			credits.color = ORANGE;
		}

		//Quit Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 20), static_cast<float>(GetScreenHeight() / 1.59), static_cast<float>(quit.width), static_cast<float>(quit.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
		{
			quit.color = BLUE;
		}
		else
		{
			quit.color = ORANGE;
		}

		//ReturnMenu Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 2.17), static_cast<float>(GetScreenHeight() / 1.1), static_cast<float>(quit.width), static_cast<float>(quit.height) }) && optionSelect != 1)
		{
			returnMenu.color = BLUE;
		}
		else
		{
			returnMenu.color = ORANGE;
		}

		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 6), static_cast<float>(GetScreenHeight() / 1.5), static_cast<float>(singlePlayer.width), static_cast<float>(singlePlayer.height) }))
		{
			singlePlayer.color = BLUE;
		}
		else
		{
			singlePlayer.color = ORANGE;
		}

		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 1.55), static_cast<float>(GetScreenHeight() / 1.5), static_cast<float>(multiPlayer.width), static_cast<float>(multiPlayer.height) }))
		{
			multiPlayer.color = BLUE;
		}
		else
		{
			multiPlayer.color = ORANGE;
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
			if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 2.17), static_cast<float>(GetScreenHeight() / 1.1), static_cast<float>(quit.width), static_cast<float>(quit.height) }))
			{
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1)
				{
					optionSelect = 0;
					playGame = false;
				}
			}

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

		DrawTextEx(gameFont, " Moon\nPatrol", { static_cast<float>(GetScreenWidth() - 350) , static_cast<float>(GetScreenHeight() / 20) }, 100, 10, GOLD);

		//Play Button

		DrawRectangle(static_cast<int>(GetScreenWidth() / 20), static_cast<int>(GetScreenHeight() / 3.5), static_cast<int>(play.width), static_cast<int>(play.height), BLANK);
		DrawTextEx(gameFont, "PLAY", play.pos, static_cast<float>(play.size), 0, play.color);

		//Controlls Button

		DrawRectangle(static_cast<int>(GetScreenWidth() / 20), static_cast<int>(GetScreenHeight() / 2.5), static_cast<int>(controls.width), static_cast<int>(controls.height), BLANK);
		DrawTextEx(gameFont, "CONTROLS", controls.pos, static_cast<float>(controls.size), 0, controls.color);

		//Rules Button

		DrawRectangle(static_cast<int>(GetScreenWidth() / 20), static_cast<int>(GetScreenHeight() / 1.94), static_cast<int>(rules.width), static_cast<int>(rules.height), BLANK);
		DrawTextEx(gameFont, "RULES", rules.pos, static_cast<float>(rules.size), 0, rules.color);

		//Credits Button

		DrawRectangle(static_cast<int>(GetScreenWidth() / 1.5), static_cast<int>(GetScreenHeight() / 1.13), static_cast<int>(credits.width), static_cast<int>(credits.height), BLANK);
		DrawTextEx(gameFont, "CREDITS", credits.pos, static_cast<float>(credits.size), 0, credits.color);

		//Quit Button

		DrawRectangle(static_cast<int>(GetScreenWidth() / 20), static_cast<int>(GetScreenHeight() / 1.59), static_cast<int>(quit.width), static_cast<int>(quit.height), BLANK);
		DrawTextEx(gameFont, "QUIT", quit.pos, static_cast<float>(quit.size), 0, quit.color);
	}

	void DrawPlayMenu(Font gameFont, Player player, Player player2)
	{
		ClearBackground(BLACK);

		DrawTextEx(gameFont, "SinglePlayer", { static_cast<float>(GetScreenWidth() / 12) , static_cast<float>(GetScreenHeight() / 6) }, 60, 0, ORANGE);
		DrawTextEx(gameFont, "MultiPlayer", { static_cast<float>(GetScreenWidth() / 1.7) , static_cast<float>(GetScreenHeight() / 6) }, 60, 0, ORANGE);

		DrawTextureEx(player.playerTexture, { static_cast<float>(GetScreenWidth() / 6), static_cast<float>(GetScreenHeight() / 2.5) }, 0.0f, 2.0f, player.color);
		
		DrawTextureEx(player.playerTexture, { static_cast<float>(GetScreenWidth() / 1.55), static_cast<float>(GetScreenHeight() / 3.4) }, 0.0f, 2.0f, player.color);
		DrawTextureEx(player2.playerTexture, { static_cast<float>(GetScreenWidth() / 1.55), static_cast<float>(GetScreenHeight() / 2) }, 0.0f, 2.0f, player.color);

		DrawRectangle(static_cast<int>(GetScreenWidth() / 6), static_cast<int>(GetScreenHeight() / 1.5), static_cast<int>(singlePlayer.width), static_cast<int>(singlePlayer.height), RED);
		DrawTextEx(gameFont, "1 Player", singlePlayer.pos, static_cast<float>(singlePlayer.size), 0, singlePlayer.color);

		DrawRectangle(static_cast<int>(GetScreenWidth() / 1.55), static_cast<int>(GetScreenHeight() / 1.5), static_cast<int>(multiPlayer.width), static_cast<int>(multiPlayer.height), RED);
		DrawTextEx(gameFont, "2 Players", multiPlayer.pos, static_cast<float>(multiPlayer.size), 0, multiPlayer.color);

		//ReturnMenu Button

		//DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), static_cast<int>(GetScreenHeight() / 1.1), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
		DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), 0, returnMenu.color);
	}

	void DrawControls(Font gameFont)
	{
		ClearBackground(BLACK);

		DrawTextEx(gameFont, "Controls", { static_cast<float>(GetScreenWidth() / 2.8) , static_cast<float>(GetScreenHeight() / 15) }, 60, 0, ORANGE);

		//ReturnMenu Button

		//DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), static_cast<int>(GetScreenHeight() / 1.1), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
		DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), 0, returnMenu.color);
	}

	void DrawRules(Font gameFont)
	{
		ClearBackground(BLACK);

		DrawTextEx(gameFont, "RULES", { static_cast<float>(GetScreenWidth() / 2.7) , static_cast<float>(GetScreenHeight() / 15) }, 60, 0, ORANGE);

		DrawTextEx(gameFont, "Play as a pilot who must escape from a city besieged by aliens.\nYou have 3 lives, if you hit an obstacle or an enemy\nprojectile you lose.",
			{ static_cast<float>(GetScreenWidth() / 8) , static_cast<float>(GetScreenHeight() / 5) }, 30, 0, ORANGE);

		//ReturnMenu Button
		
		//DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), static_cast<int>(GetScreenHeight() / 1.1), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
		DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), 0, returnMenu.color);
	}

	void DrawCredits(Font gameFont)
	{
		ClearBackground(BLACK);

		DrawTextEx(gameFont, "CREDITS", { static_cast<float>(GetScreenWidth() / 3.8) , static_cast<float>(GetScreenHeight() / 15) }, 60, 0, ORANGE);

		DrawTextEx(gameFont, "GAME MADE BY", { static_cast<float>(GetScreenWidth() / 3.5) , static_cast<float>(GetScreenHeight() / 3.5) }, 40, 0, GOLD);
		DrawTextEx(gameFont, "Facundo Santos", { static_cast<float>(GetScreenWidth() / 2.8) , static_cast<float>(GetScreenHeight() / 2.8) }, 40, 0, ORANGE);

		DrawTextEx(gameFont, "FONT", { static_cast<float>(GetScreenWidth() / 2.3) , static_cast<float>(GetScreenHeight() / 2) }, 30, 0, GOLD);

		//ReturnMenu Button
		//DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), static_cast<int>(GetScreenHeight() / 1.1), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
		DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), 0, returnMenu.color);
	}
}