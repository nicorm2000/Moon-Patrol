#include <iostream>
#include "raylib.h"
#include "Window/PlayGame.h"
#include "Objects/Player.h"
#include "Objects/GameComps.h"
#include "Objects/Floor.h"
#include "Objects/Obstacle.h"


//Window
int screenWidth = 1024;
int screenHeight = 768;

//Player
Player player = CreatePlayer(screenWidth, screenHeight);

//Floor
Ground ground = CreateGround(screenWidth, screenHeight);

//Obstacle
Obstacle obstacle = CreateObstacle(screenWidth, screenHeight);

void initGame()
{
    InitWindow(screenWidth, screenHeight, "Moon Patrol");
}

void Update()
{
    while (!WindowShouldClose())
    {
        ObstacleMovement();
        PlayerMovement();
        Collisions();
        Draw();
    }
    
    CloseWindow();
}

void Draw()
{
    BeginDrawing();

    ClearBackground(BLACK);
    
    DrawGround(ground);
    DrawObstacle(obstacle);
    DrawPlayer(player);

    EndDrawing();
}

void PlayGame()
{
    initGame();

    Update();
}

void Collisions()
{

}

bool CheckCollisionRecRec(Vector2 r1, float r1w, float r1h, Vector2 r2, float r2w, float r2h)
{
    if (r1.x + r1w >= r2.x &&
        r1.x <= r2.x + r2w &&
        r1.y + r1h >= r2.y &&
        r1.y <= r2.y + r2h)
    {
        return true;
    }
    return false;
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

    PlayerLimit(player, screenWidth);
}

void ObstacleMovement()
{
    obstacle.pos.x -= obstacle.speed * GetFrameTime();

    ObstacleTeleport(obstacle, screenWidth);
}