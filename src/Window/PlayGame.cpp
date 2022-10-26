#include <iostream>
#include "raylib.h"
#include "Window/PlayGame.h"
#include "Objects/Player.h"
#include "Objects/GameComps.h"

//Window
int screenWidth = 1024;
int screenHeight = 768;

//Player
Player player = CreatePlayer(screenWidth, screenHeight);

void initGame()
{
    InitWindow(screenWidth, screenHeight, "Moon Patrol");
}

void Update()
{
    while (!WindowShouldClose())
    {
        Draw();
    }
    
    CloseWindow();
}

void Draw()
{
    BeginDrawing();

    ClearBackground(BLACK);

    DrawRectangle(static_cast<int>(player.pos.x), 
                  static_cast<int>(player.pos.y), 
                  static_cast<int>(player.width), 
                  static_cast<int>(player.height), player.color);

    

    EndDrawing();
}

void PlayGame()
{
    initGame();

    Update();
}

void PlayerMovement()
{

}