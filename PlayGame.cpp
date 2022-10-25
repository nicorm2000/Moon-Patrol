#include <iostream>
#include "raylib.h"
#include "Window/Game.h"

void PlayGame()
{
    const int screenWidth = 1024;
    const int screenHeight = 768;

    InitWindow(screenWidth, screenHeight, "Moon Patrol");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", screenWidth / 4, screenHeight / 2, 20, LIGHTGRAY);

        EndDrawing();

    }

    CloseWindow();
}