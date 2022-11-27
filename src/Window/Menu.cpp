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

		float playPosXDivider = 20.0f;
		float playPosYDivider = 3.5f;
		float playWidthDivider = 8.0f;
		float playHeightDivider = 16.0f;

		play.pos.x = static_cast<float>(GetScreenWidth() / playPosXDivider);
		play.pos.y = static_cast<float>(GetScreenHeight() / playPosYDivider);
		play.width = static_cast<float>(GetScreenWidth() / playWidthDivider);
		play.height = static_cast<float>(GetScreenHeight() / playHeightDivider);
		play.size = 40;
		play.isActive = false;
		play.texture = LoadTexture("resources/Sprites/menuBg.png");

		play.color = BEIGE;

		//SinglePlayer Button

		float singlePlayerPosXDivider = 5.9f;
		float singlePlayerPosYDivider = 1.5f;
		float singlePlayerWidthDivider = 5.0f;
		float singlePlayerHeightDivider = 16.0f;

		singlePlayer.pos.x = static_cast<float>(GetScreenWidth() / singlePlayerPosXDivider);
		singlePlayer.pos.y = static_cast<float>(GetScreenHeight() / singlePlayerPosYDivider);
		singlePlayer.width = static_cast<float>(GetScreenWidth() / singlePlayerWidthDivider);
		singlePlayer.height = static_cast<float>(GetScreenHeight() / singlePlayerHeightDivider);
		singlePlayer.size = 40;
		singlePlayer.isActive = false;
		singlePlayer.texture = LoadTexture("resources/Sprites/Bg.png");

		singlePlayer.color = BEIGE;

		//MultiPlayer Button
		
		float multiPlayerPosXDivider = 1.55f;
		float multiPlayerPosYDivider = 1.5f;
		float multiPlayerWidthDivider = 4.0f;
		float multiPlayerHeightDivider = 16.0f;

		multiPlayer.pos.x = static_cast<float>(GetScreenWidth() / multiPlayerPosXDivider);
		multiPlayer.pos.y = static_cast<float>(GetScreenHeight() / multiPlayerPosYDivider);
		multiPlayer.width = static_cast<float>(GetScreenWidth() / multiPlayerWidthDivider);
		multiPlayer.height = static_cast<float>(GetScreenHeight() / multiPlayerHeightDivider);
		multiPlayer.size = 40;
		multiPlayer.isActive = false;

		multiPlayer.color = BEIGE;

		//Controls Button
		
		float controlsPosXDivider = 20.0f;
		float controlsPosYDivider = 2.5f;
		float controlsWidthDivider = 3.8f;
		float controlsHeightDivider = 16.0f;

		controls.pos.x = static_cast<float>(GetScreenWidth() / controlsPosXDivider);
		controls.pos.y = static_cast<float>(GetScreenHeight() / controlsPosYDivider);
		controls.width = static_cast<float>(GetScreenWidth() / controlsWidthDivider);
		controls.height = static_cast<float>(GetScreenHeight() / controlsHeightDivider);
		controls.size = 40;
		controls.isActive = false;
		controls.texture = LoadTexture("resources/Sprites/controlsBg.png");

		controls.color = BEIGE;

		//Rules Button

		float rulesPosXDivider = 20.0f;
		float rulesPosYDivider = 1.93f;
		float rulesWidthDivider = 6.0f;
		float rulesHeightDivider = 16.0f;

		rules.pos.x = static_cast<float>(GetScreenWidth() / rulesPosXDivider);
		rules.pos.y = static_cast<float>(GetScreenHeight() / rulesPosYDivider);
		rules.width = static_cast<float>(GetScreenWidth() / rulesWidthDivider);
		rules.height = static_cast<float>(GetScreenHeight() / rulesHeightDivider);
		rules.size = 40;
		rules.isActive = false;
		rules.texture = LoadTexture("resources/Sprites/rulesBg.png");

		rules.color = BEIGE;

		//Credits Button

		float creditsPosXDivider = 1.5f;
		float creditsPosYDivider = 1.13f;
		float creditsWidthDivider = 4.5f;
		float creditsHeightDivider = 16.0f;

		credits.pos.x = static_cast<float>(GetScreenWidth() / creditsPosXDivider);
		credits.pos.y = static_cast<float>(GetScreenHeight() / creditsPosYDivider);
		credits.width = static_cast<float>(GetScreenWidth() / creditsWidthDivider);
		credits.height = static_cast<float>(GetScreenHeight() / creditsHeightDivider);
		credits.size = 40;
		credits.isActive = false;
		credits.texture = LoadTexture("resources/Sprites/creditsBg.png");

		credits.color = BEIGE;

		//Quit Button

		float quitPosXDivider = 20.0f;
		float quitPosYDivider = 1.59f;
		float quitWidthDivider = 8.2f;
		float quitHeightDivider = 16.0f;

		quit.pos.x = static_cast<float>(GetScreenWidth() / quitPosXDivider);
		quit.pos.y = static_cast<float>(GetScreenHeight() / quitPosYDivider);
		quit.width = static_cast<float>(GetScreenWidth() / quitWidthDivider);
		quit.height = static_cast<float>(GetScreenHeight() / quitHeightDivider);
		quit.size = 40;
		quit.isActive = false;

		quit.color = BEIGE;

		//ReturnMenu Button

		float returnPosXDivider = 2.1f;
		float returnPosYDivider = 1.1f;
		float returnWidthDivider = 8.0f;
		float returnHeightDivider = 16.0f;

		returnMenu.pos.x = static_cast<float>(GetScreenWidth() / returnPosXDivider);
		returnMenu.pos.y = static_cast<float>(GetScreenHeight() / returnPosYDivider);
		returnMenu.width = static_cast<float>(GetScreenWidth() / returnWidthDivider);
		returnMenu.height = static_cast<float>(GetScreenHeight() / returnHeightDivider);
		returnMenu.size = 40;
		returnMenu.isActive = false;

		returnMenu.color = BEIGE;
	}

	void MenuCollisions(Mouse& mouse, int& optionSelect)
	{
		//Play Button

		float playPosXDivider = 20.0f;
		float playPosYDivider = 3.5f;

		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / playPosXDivider), static_cast<float>(GetScreenHeight() / playPosYDivider), static_cast<float>(play.width), static_cast<float>(play.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
		{
			play.color = BLUE;
		}
		else
		{
			play.color = BEIGE;
		}

		//Controls Button

		float controlsPosXDivider = 20.0f;
		float controlsPosYDivider = 2.5f;

		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / controlsPosXDivider), static_cast<float>(GetScreenHeight() / controlsPosYDivider), static_cast<float>(controls.width), static_cast<float>(controls.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
		{
			controls.color = BLUE;
		}
		else
		{
			controls.color = BEIGE;
		}

		//Rules Button

		float rulesPosXDivider = 20.0f;
		float rulesPosYDivider = 1.93f;

		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / rulesPosXDivider), static_cast<float>(GetScreenHeight() / rulesPosYDivider), static_cast<float>(rules.width), static_cast<float>(rules.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
		{
			rules.color = BLUE;
		}
		else
		{
			rules.color = BEIGE;
		}

		//Credits Button
		
		float creditsPosXDivider = 1.5f;
		float creditsPosYDivider = 1.13f;
		
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / creditsPosXDivider), static_cast<float>(GetScreenHeight() / creditsPosYDivider), static_cast<float>(credits.width), static_cast<float>(credits.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
		{
			credits.color = BLUE;
		}
		else
		{
			credits.color = BEIGE;
		}

		//Quit Button

		float quitPosXDivider = 20.0f;
		float quitPosYDivider = 1.59f;

		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / quitPosXDivider), static_cast<float>(GetScreenHeight() / quitPosYDivider), static_cast<float>(quit.width), static_cast<float>(quit.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
		{
			quit.color = BLUE;
		}
		else
		{
			quit.color = BEIGE;
		}

		//ReturnMenu Button

		float returnPosXDivider = 2.1f;
		float returnPosYDivider = 1.1f;

		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / returnPosXDivider), static_cast<float>(GetScreenHeight() / returnPosYDivider), static_cast<float>(quit.width), static_cast<float>(quit.height) }) && optionSelect != 1)
		{
			returnMenu.color = BLUE;
		}
		else
		{
			returnMenu.color = BEIGE;
		}

		//SinglePlayer Button
		
		float singlePlayerPosXDivider = 5.9f;
		float singlePlayerPosYDivider = 1.5f;
		
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / singlePlayerPosXDivider), static_cast<float>(GetScreenHeight() / singlePlayerPosYDivider), static_cast<float>(singlePlayer.width), static_cast<float>(singlePlayer.height) }))
		{
			singlePlayer.color = BLUE;
		}
		else
		{
			singlePlayer.color = BEIGE;
		}

		//MultiPlayer Button
		
		float multiPlayerPosXDivider = 1.55f;
		float multiPlayerPosYDivider = 1.5f;
		
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / multiPlayerPosXDivider), static_cast<float>(GetScreenHeight() / multiPlayerPosYDivider), static_cast<float>(multiPlayer.width), static_cast<float>(multiPlayer.height) }))
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

			float playPosXDivider = 20.0f;
			float playPosYDivider = 3.5f;

			if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / playPosXDivider), static_cast<float>(GetScreenHeight() / playPosYDivider), static_cast<float>(play.width), static_cast<float>(play.height) }))
			{
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
				{
					optionSelect = 6;
				}
			}

			//Controls Button

			float controlsPosXDivider = 20.0f;
			float controlsPosYDivider = 2.5f;

			if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / controlsPosXDivider), static_cast<float>(GetScreenHeight() / controlsPosYDivider), static_cast<float>(controls.width), static_cast<float>(controls.height) }))
			{
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
				{
					optionSelect = 2;
				}
			}

			//Rules Button

			float rulesPosXDivider = 20.0f;
			float rulesPosYDivider = 1.93f;

			if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / rulesPosXDivider), static_cast<float>(GetScreenHeight() / rulesPosYDivider), static_cast<float>(rules.width), static_cast<float>(rules.height) }))
			{
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
				{
					optionSelect = 3;
				}
			}

			//Credits Button

			float creditsPosXDivider = 1.5f;
			float creditsPosYDivider = 1.13f;

			if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / creditsPosXDivider), static_cast<float>(GetScreenHeight() / creditsPosYDivider), static_cast<float>(credits.width), static_cast<float>(credits.height) }))
			{
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
				{
					optionSelect = 4;
				}
			}

			//Quit Button

			float quitPosXDivider = 20.0f;
			float quitPosYDivider = 1.59f;

			if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / quitPosXDivider), static_cast<float>(GetScreenHeight() / quitPosYDivider), static_cast<float>(quit.width), static_cast<float>(quit.height) }))
			{
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
				{
					optionSelect = 5;
				}
			}

			//ReturnMenu Button

			float returnPosXDivider = 2.1f;
			float returnPosYDivider = 1.1f;

			if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / returnPosXDivider), static_cast<float>(GetScreenHeight() / returnPosYDivider), static_cast<float>(quit.width), static_cast<float>(quit.height) }))
			{
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1)
				{
					optionSelect = 0;
					playGame = false;
				}
			}

			//SinglePlayer Button

			float singlePlayerPosXDivider = 5.9f;
			float singlePlayerPosYDivider = 1.5f;

			if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / singlePlayerPosXDivider), static_cast<float>(GetScreenHeight() / singlePlayerPosYDivider), static_cast<float>(singlePlayer.width), static_cast<float>(singlePlayer.height) }))
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

			float multiPlayerPosXDivider = 1.55f;
			float multiPlayerPosYDivider = 1.5f;

			if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / multiPlayerPosXDivider), static_cast<float>(GetScreenHeight() / multiPlayerPosYDivider), static_cast<float>(multiPlayer.width), static_cast<float>(multiPlayer.height) }))
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

		float wordsSpacing = 10.0f;
		
		//Play Button

		//DrawRectangle(static_cast<int>(GetScreenWidth() / 20), static_cast<int>(GetScreenHeight() / 3.5), static_cast<int>(play.width), static_cast<int>(play.height), BLANK);
		DrawTextEx(gameFont, "PLAY", play.pos, static_cast<float>(play.size), wordsSpacing, play.color);

		//Controls Button

		//DrawRectangle(static_cast<int>(GetScreenWidth() / 20), static_cast<int>(GetScreenHeight() / 2.5), static_cast<int>(controls.width), static_cast<int>(controls.height), BLANK);
		DrawTextEx(gameFont, "CONTROLS", controls.pos, static_cast<float>(controls.size), wordsSpacing, controls.color);

		//Rules Button

		//DrawRectangle(static_cast<int>(GetScreenWidth() / 20), static_cast<int>(GetScreenHeight() / 1.94), static_cast<int>(rules.width), static_cast<int>(rules.height), BLANK);
		DrawTextEx(gameFont, "RULES", rules.pos, static_cast<float>(rules.size), wordsSpacing, rules.color);

		//Credits Button

		//DrawRectangle(static_cast<int>(GetScreenWidth() / 1.5), static_cast<int>(GetScreenHeight() / 1.13), static_cast<int>(credits.width), static_cast<int>(credits.height), BLANK);
		DrawTextEx(gameFont, "CREDITS", credits.pos, static_cast<float>(credits.size), wordsSpacing, credits.color);

		//Quit Button

		//DrawRectangle(static_cast<int>(GetScreenWidth() / 20), static_cast<int>(GetScreenHeight() / 1.59), static_cast<int>(quit.width), static_cast<int>(quit.height), BLANK);
		DrawTextEx(gameFont, "QUIT", quit.pos, static_cast<float>(quit.size), wordsSpacing, quit.color);
	}

	void DrawPlayMenu(Font gameFont, Player player, Player player2)
	{
		ClearBackground(BLACK);

		int menuPos = 0;

		DrawTexture(singlePlayer.texture, menuPos, menuPos, WHITE);

		float wordsSpacing = 10.0f;
		float wordsFontSize = 60.0f;
		float singlePlayerPosXDivider = 12.0f;
		float multiPlayerPosYDivider = 1.7f;
		float playerPosYDivider = 6.0f;
		float menuTexturePosXDivider = 6.0f;
		float menuTexturePosYXDivider = 2.5f;
		float menuTextureRotation = 0.0f;
		float menuTextureScale = 2.0f;
		float playerTexturePosXDivider = 1.55f;
		float singlePlayerTexturePosYDivider = 3.4f;
		float multiPlayerTexturePosYDivider = 2.0f;

		DrawTextEx(gameFont, "SinglePlayer", { static_cast<float>(GetScreenWidth() / singlePlayerPosXDivider) , static_cast<float>(GetScreenHeight() / playerPosYDivider) }, wordsFontSize, wordsSpacing, WHITE);
		DrawTextEx(gameFont, "MultiPlayer", { static_cast<float>(GetScreenWidth() / multiPlayerPosYDivider) , static_cast<float>(GetScreenHeight() / playerPosYDivider) }, wordsFontSize, wordsSpacing, WHITE);

		DrawTextureEx(player.playerTexture, { static_cast<float>(GetScreenWidth() / menuTexturePosXDivider), static_cast<float>(GetScreenHeight() / menuTexturePosYXDivider) }, menuTextureRotation, menuTextureScale, player.color);
		
		DrawTextureEx(player.playerTexture, { static_cast<float>(GetScreenWidth() / playerTexturePosXDivider), static_cast<float>(GetScreenHeight() / singlePlayerTexturePosYDivider) }, menuTextureRotation, menuTextureScale, player.color);
		DrawTextureEx(player2.playerTexture, { static_cast<float>(GetScreenWidth() / playerTexturePosXDivider), static_cast<float>(GetScreenHeight() / multiPlayerTexturePosYDivider) }, menuTextureRotation, menuTextureScale, player.color);

		//1 Player Button

		//DrawRectangle(static_cast<int>(GetScreenWidth() / 6), static_cast<int>(GetScreenHeight() / 1.5), static_cast<int>(singlePlayer.width), static_cast<int>(singlePlayer.height), BLANK);
		DrawTextEx(gameFont, "1 Player", singlePlayer.pos, static_cast<float>(singlePlayer.size), wordsSpacing, singlePlayer.color);

		//2 Players Button

		//DrawRectangle(static_cast<int>(GetScreenWidth() / 1.55), static_cast<int>(GetScreenHeight() / 1.5), static_cast<int>(multiPlayer.width), static_cast<int>(multiPlayer.height), BLANK);
		DrawTextEx(gameFont, "2 Players", multiPlayer.pos, static_cast<float>(multiPlayer.size), wordsSpacing, multiPlayer.color);

		//ReturnMenu Button

		//DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), static_cast<int>(GetScreenHeight() / 1.1), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
		DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), wordsSpacing, returnMenu.color);
	}

	void DrawControls(Font gameFont)
	{
		ClearBackground(BLACK);

		int menuPos = 0;

		DrawTexture(controls.texture, menuPos, menuPos, WHITE);

		//ReturnMenu Button

		float wordsSpacing = 10.0f;

		//DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), static_cast<int>(GetScreenHeight() / 1.1), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
		DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), wordsSpacing, returnMenu.color);
	}

	void DrawRules(Font gameFont)
	{
		ClearBackground(BLACK);

		int menuPos = 0;

		DrawTexture(rules.texture, menuPos, menuPos, WHITE);

		//ReturnMenu Button
		
		float wordsSpacing = 10.0f;

		//DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), static_cast<int>(GetScreenHeight() / 1.1), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
		DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), wordsSpacing, returnMenu.color);
	}

	void DrawCredits(Font gameFont)
	{
		ClearBackground(BLACK);

		int menuPos = 0;

		DrawTexture(credits.texture, menuPos, menuPos, WHITE);

		//ReturnMenu Button
 
		float wordsSpacing = 10.0f;

		//DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5), static_cast<int>(GetScreenHeight() / 1.1), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
		DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), wordsSpacing, returnMenu.color);
	}

	void UnloadMenu()
	{
		UnloadTexture(play.texture);
		UnloadTexture(singlePlayer.texture);
		UnloadTexture(multiPlayer.texture);
		UnloadTexture(controls.texture);
		UnloadTexture(rules.texture);
		UnloadTexture(credits.texture);
		UnloadTexture(quit.texture);
		UnloadTexture(returnMenu.texture);
	}
}