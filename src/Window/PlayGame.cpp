#include <iostream>
#include "raylib.h"
#include "Window/PlayGame.h"
#include "Objects/Player.h"
#include "Objects/GameComps.h"
#include "Objects/Floor.h"

//Window
int screenWidth = 1024;
int screenHeight = 768;

//Player
Player player = CreatePlayer(screenWidth, screenHeight);

//Floor
Ground ground = CreateGround(screenWidth, screenHeight);


void initGame()
{
    InitWindow(screenWidth, screenHeight, "Moon Patrol");
}

void Update()
{
    while (!WindowShouldClose())
    {
        PlayerMovement();
        Draw();
    }
    
    CloseWindow();
}

void Draw()
{
    BeginDrawing();

    ClearBackground(BLACK);
    
    DrawGround(ground);
    DrawPlayer(player);

    EndDrawing();
}

void PlayGame()
{
    initGame();

    Update();
}

void PlayerMovement()
{
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        player.pos.x -= player.speed * GetFrameTime();
    }

    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        player.pos.x += player.speed * GetFrameTime();
    }

    if (IsKeyDown(KEY_SPACE))
    {
        player.pos.y = static_cast<float>(screenHeight / 1.5);
    }

    if (!IsKeyDown(KEY_SPACE))
    {
        player.pos.y = static_cast<float>(screenHeight / 1.15);
    }
}