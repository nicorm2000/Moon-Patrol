#include <iostream>
#include "raylib.h"
#include "Window/PlayGame.h"
#include "Objects/Player.h"
#include "Objects/GameComps.h"
#include "Objects/Floor.h"
#include "Objects/Obstacle.h"

using namespace std;

//Window
int screenWidth = 1024;
int screenHeight = 768;
bool pause = true;

//Player
Player player = CreatePlayer(screenWidth, screenHeight);

//Floor
Ground ground = CreateGround(screenWidth, screenHeight);

//Obstacle
Obstacle obstacle = CreateObstacle(screenWidth, screenHeight);

void initGame()
{
    InitWindow(screenWidth, screenHeight, "Moon Patrol v0.1");
    SetExitKey(NULL);
}

void GameLoop()
{
    while (!WindowShouldClose())
    {
        pauseIntputs();

        if (!pause)
        {
            Update();
            Collisions();
        }

        Draw();
    }

    CloseWindow();
}
void Update()
{
    ObstacleMovement();
    PlayerMovement();
}

void Draw()
{
    BeginDrawing();

    ClearBackground(BLACK);
    
    DrawGround(ground);
    DrawObstacle(obstacle);
    DrawPlayer(player);

    if (pause)
    {
        DrawText("PAUSE ON- Esc or P to set Off", screenWidth / screenWidth, screenHeight / screenHeight, 50, WHITE);
    }

    EndDrawing();
}

void PlayGame()
{
    initGame();

    GameLoop();
}

void Collisions()
{
    PlayerCollision();
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

void PlayerCollision()
{
    if (CheckCollisionRecRec(player.pos, player.width - 30, player.height -30, obstacle.pos, obstacle.width, obstacle.height))
    {
        player.color = RED;
        cout << "Perdiste" << endl;
        RestartGame();
    }

    else
    {
        player.color = GREEN;
    }
}

void ObstacleMovement()
{
    obstacle.pos.x -= obstacle.speed * GetFrameTime();

    ObstacleTeleport(obstacle, screenWidth);
}

void pauseIntputs() 
{
    if (pause)
    {
        if (IsKeyPressed(KEY_P) || IsKeyPressed(KEY_ESCAPE))
        {
            pause = false;
        }
    }

    else
    {
        if (IsKeyPressed(KEY_P) || IsKeyPressed(KEY_ESCAPE))
        {
            pause = true;
        }
    }
}

void RestartGame()
{
    //Player
    player.pos.x = static_cast<float>(screenWidth / 6);
    player.pos.y = static_cast<float>(screenHeight / 1.15);
    player.width = 80;
    player.height = 40;
    player.speed = 420;
    player.color = GREEN;

    //Obstacle
    obstacle.pos.x = static_cast<float>(screenWidth - 10);
    obstacle.pos.y = static_cast<float>(screenHeight / 1.2);
    obstacle.width = 30;
    obstacle.height = 60;
    obstacle.speed = 300;
    obstacle.color = BLUE;

    //Ground
    ground.pos.x = static_cast<float>(screenWidth / screenWidth);
    ground.pos.y = static_cast<float>(screenHeight / 1.1);
    ground.width = static_cast<float>(screenWidth);
    ground.height = 70;
    ground.color = YELLOW;
}