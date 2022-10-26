#include <iostream>
#include "raylib.h"
#include "Window/PlayGame.h"

//Window
const int screenWidth = 1024;
const int screenHeight = 768;


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
}

void Draw()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("Congrats! You created your first window!", screenWidth / 4, screenHeight / 2, 20, LIGHTGRAY);

    EndDrawing();
}

void PlayGame()
{
    initGame();

    Update();

    CloseWindow();
}