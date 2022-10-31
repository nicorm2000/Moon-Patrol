#include <iostream>
#include "raylib.h"
#include "Window/PlayGame.h"
#include "Window/GameComps.h"
#include "Window/Menu.h"
#include "Objects/Player.h"
#include "Objects/Floor.h"
#include "Objects/Obstacle.h"
#include "Objects/Background.h"
#include "Objects/Mouse.h"

using namespace std;

namespace game 
{
    //Window
    int screenWidth = 1024;
    int screenHeight = 768;
    bool pause = true;

    //Menu
    int optionSelect = 0;
    bool playGame = false;

    //Player
    Player player = CreatePlayer(screenWidth, screenHeight);

    //Floor
    Ground ground = CreateGround(screenWidth, screenHeight);

    //Obstacle
    Obstacle obstacle = CreateObstacle(screenWidth, screenHeight);

    //Background
    Background sky = CreateBackground(screenWidth, screenHeight);
    Background sky2 = CreateBackground(screenWidth, screenHeight);

    Background city = CreateBackground(screenWidth, screenHeight);
    Background city2 = CreateBackground(screenWidth, screenHeight);

    //Mouse
    Mouse mouse = CreateMouse();

    //Font
    Font gameFont;

    void initGame()
    {
        InitWindow(screenWidth, screenHeight, "Moon Patrol v0.2");
        SetExitKey(NULL);

        //Menu
        InitMenu();

        //Font
        gameFont = LoadFont("resources/Font/baby blocks.ttf");
        
        //Background
        sky.pos.x = static_cast<float>(screenWidth / screenWidth);
        sky.tex = LoadTexture("resources/Sprites/Sky.png");
        
        sky2.pos.x = static_cast<float>(screenWidth / screenWidth + sky.width);
        sky2.tex = LoadTexture("resources/Sprites/Sky.png");

        city.pos.x = static_cast<float>(screenWidth / screenWidth);
        city.pos.y = static_cast<float>((screenHeight / screenHeight) - 60);
        city.tex = LoadTexture("resources/Sprites/City.png");
        city.speed = 200;
        
        city2.pos.x = static_cast<float>(screenWidth / screenWidth + city2.width);
        city2.pos.y = static_cast<float>((screenHeight / screenHeight) - 60);
        city2.tex = LoadTexture("resources/Sprites/City.png");
        city2.speed = 200;

        //Ground 
        ground.tex = LoadTexture("resources/Sprites/Ground.png");
    }

    void GameLoop()
    {
        HideCursor();
        bool gameOn = true;
        
        if (gameOn == true)
        {
            while (!WindowShouldClose() && gameOn)
            {
                pauseIntputs();
                MouseMovement();
                MenuCollisions(mouse, optionSelect);
                MenuInputs(mouse, optionSelect, playGame);

                if (playGame == true)
                {
                    if (!pause)
                    {
                        Update();
                        Collisions();
                    }
                }

                switch (optionSelect)
                {
                    case static_cast<int>(Menu::MainMenu):
                        BeginDrawing();
                        ClearBackground(BLACK);
                        ShowCursor();
                        DrawMenu(gameFont);
                        EndDrawing();

                        break;

                    case static_cast<int>(Menu::Play):
                        Draw();
                        break;

                    case static_cast<int>(Menu::Controlls):
                        BeginDrawing();
                        ClearBackground(BLACK);
                        DrawControlls(gameFont);
                        EndDrawing();
                        break;

                    case static_cast<int>(Menu::Rules):
                        BeginDrawing();
                        ClearBackground(BLACK);
                        DrawRules(gameFont);
                        EndDrawing();
                        break;

                    case static_cast<int>(Menu::Credits):
                        BeginDrawing();
                        ClearBackground(BLACK);
                        DrawCredits(gameFont);
                        EndDrawing();
                        break;

                    case static_cast<int>(Menu::Quit):
                        gameOn = false;
                        break;
                }
            }
        }
        
        if (!gameOn)
        {
            CloseWindow();
        }
    }

    void Update()
    {
        ObstacleMovement();
        PlayerMovement();
        BackgroundMovement();
    }

    void Draw()
    {
        BeginDrawing();

        ClearBackground(BLACK);
        DrawBackground(sky);
        DrawBackground(sky2);
        DrawBackground(city);
        DrawBackground(city2);
        DrawGround(ground);
        DrawObstacle(obstacle);
        DrawPlayer(player);
        DrawMouse(mouse, mouse.mouseRec);

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
        if (CheckCollisionRecRec(player.pos, player.width - 30, player.height - 30, obstacle.pos, obstacle.width, obstacle.height))
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

    void MouseMovement()
    {
        mouse.position = GetMousePosition();
    }

    void BackgroundMovement()
    {
        sky.pos.x -= sky.speed * GetFrameTime();
        sky2.pos.x -= sky2.speed * GetFrameTime();

        city.pos.x -= city.speed * GetFrameTime();
        city2.pos.x -= city2.speed * GetFrameTime();

        BackgroundParallax(sky, screenWidth);
        BackgroundParallax(sky2, screenWidth);
        BackgroundParallax(city, screenWidth);
        BackgroundParallax(city2, screenWidth);
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

        //Mouse
        mouse.position.x = 0;
        mouse.position.y = 0;
        mouse.width = 20.0f;
        mouse.height = 20.0f;
        mouse.mouseRec = GetRecMouse(mouse);
    }
}