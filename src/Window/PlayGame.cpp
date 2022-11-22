#include <iostream>
#include "raylib.h"
#include "Window/PlayGame.h"
#include "Window/Menu.h"
#include "Objects/Player.h"
#include "Objects/Bullet.h"
#include "Objects/Floor.h"
#include "Objects/Obstacle.h"
#include "Objects/FlyEnemy.h"
#include "Objects/Background.h"
#include "Objects/Mouse.h"

using namespace std;

namespace game 
{
    struct SubMenu
    {
        Vector2 pos;

        float width;
        float height;

        Texture texture;

        bool isActive;
    };

    struct Button
    {
        Vector2 pos;

        float width;
        float height;

        int size;

        Texture texture;

        Color color;
    };

    void InitRestartMenu();
    void InitPauseMenu();
    void SubMenusInputs(bool& gameOn);

    void MouseMovement();

    void Update();

    void ObstacleMovement();
    void ObstacleTeleport();

    void Collisions();
    bool CheckCollisionRecRec(Vector2 r1, float r1w, float r1h, Vector2 r2, float r2w, float r2h);

    void PlayerCollision(Player& play);
    void PlayerMovement();
    void PlayerJump(Player& play);
    void PlayerBulletMovement(Bullet& playerbullet, Player& play, int bulletPos);

    void BulletCollision(Bullet& playerbullet);
    void BulletCollisonLimit(Bullet& playerbullet);

    void FlyEnemyMovement();
    void FlyEnemyCollisionLimit();
    void FlyEnemyRespawn();

    void BackgroundMovement();

    void DrawPauseMenu();
    void PauseMenuCollisions();

    void DrawRestartGameMenu();
    void RestartGame();
    void RestarGameMenuCollisions();

    void UnloadData();

    //Window
    int screenWidth = 1024;
    int screenHeight = 768;

    //Menu
    int optionSelect = 0;
    bool playGame = false;
    bool coop = false;

    //Player
    Player player = CreatePlayer(screenWidth, screenHeight);
    Player secondPlayer = CreatePlayer(screenWidth, screenHeight);

    //Bullet
    int const maxBullets = 30;
    Bullet playerBullet[maxBullets];
    int const maxBullets2 = 30;
    Bullet player2Bullet[maxBullets2];

    //Floor
    Ground ground = CreateGround(screenWidth, screenHeight);

    //Obstacle
    Obstacle obstacle = CreateObstacle(screenWidth, screenHeight);

    //FlyEnemy
    int const maxflyEnemy = 5;
    FlyEnemy flyEnemy[maxflyEnemy];

    //Background
    Background sky = CreateBackground(screenWidth, screenHeight);
    Background sky2 = CreateBackground(screenWidth, screenHeight);

    Background city = CreateBackground(screenWidth, screenHeight);
    Background city2 = CreateBackground(screenWidth, screenHeight);

    Background hill = CreateBackground(screenWidth, screenHeight);
    Background hill2 = CreateBackground(screenWidth, screenHeight);

    //Mouse
    Mouse mouse = CreateMouse();

    //Restart Menu
    SubMenu restartMenu;
    Button restartButton;
    Button returnMenuButton;
    Button quitGameButton;

    //Pause Menu
    bool pause = false;
    SubMenu pauseMenu;
    Button pauseButtonOff;
    Button pauseButtonOn;
    Button resumeButton;

    //Font
    Font gameFont;

    void PlayGame()
    {
        InitGame();

        GameLoop();
    }

    void InitGame()
    {
        InitWindow(screenWidth, screenHeight, "Moon Patrol v0.3");
        SetExitKey(NULL);

        //Menu
        InitMenu();

        //RestartMenu
        InitRestartMenu();

        //PauseMenu
        InitPauseMenu();

        //Font
        gameFont = LoadFont("resources/Font/unlearn2.ttf");
        
        //Mouse
        mouse.mouseTexture = LoadTexture("resources/Sprites/mouse.png");

        //Bullet
        for (int i = 0; i < maxBullets; i++)
        {
            playerBullet[i] = CreateBullet();
        }
        
        LoadTextureBullet(playerBullet[0]);
        
        //Background
            //Sky
        sky.pos.x = static_cast<float>(screenWidth / screenWidth);
        sky.tex = LoadTexture("resources/Sprites/Sky.png");
        
        sky2.pos.x = static_cast<float>(screenWidth / screenWidth + sky.width);
        sky2.tex = LoadTexture("resources/Sprites/Sky.png");
            
            //City
        city.pos.x = static_cast<float>(screenWidth / screenWidth);
        city.pos.y = static_cast<float>((screenHeight / screenHeight) - 60);
        city.tex = LoadTexture("resources/Sprites/City.png");
        city.speed = 200;
        
        city2.pos.x = static_cast<float>(screenWidth / screenWidth + city.width);
        city2.pos.y = static_cast<float>((screenHeight / screenHeight) - 60);
        city2.tex = LoadTexture("resources/Sprites/City.png");
        city2.speed = 200;
            
            //Hill
        hill.pos.x = static_cast<float>(screenWidth / screenWidth);
        hill.pos.y = static_cast<float>((screenHeight / 1.26));
        hill.tex = LoadTexture("resources/Sprites/Hill.png");
        hill.speed = 400;

        hill2.pos.x = static_cast<float>(screenWidth / screenWidth + hill.width);
        hill2.pos.y = static_cast<float>((screenHeight / 1.26));
        hill2.tex = LoadTexture("resources/Sprites/Hill.png");
        hill2.speed = 400;

        //Ground Enemy
        obstacle.obstacleTexture = LoadTexture("resources/Sprites/GroundEnemy.png");

        //Fly Enemy
        for (int i = 0; i < maxflyEnemy; i++)
        {
            flyEnemy[i] = CreateFlyEnemy();
            flyEnemy[0].pos.x = static_cast<float>(screenWidth / -2.5);
            flyEnemy[0].pos.y = static_cast<float>(screenHeight / -2.5);

            flyEnemy[1].pos.x = static_cast<float>(screenWidth / -1.9);
            flyEnemy[1].pos.y = static_cast<float>(screenHeight / -1.9);

            flyEnemy[2].pos.x = static_cast<float>(screenWidth / -1.5);
            flyEnemy[2].pos.y = static_cast<float>(screenHeight / -1.5);

            flyEnemy[3].pos.x = static_cast<float>(screenWidth / -1.22);
            flyEnemy[3].pos.y = static_cast<float>(screenHeight / -1.22);

            flyEnemy[4].pos.x = static_cast<float>(screenWidth / -1.05);
            flyEnemy[4].pos.y = static_cast<float>(screenHeight / -1.05);
        }
        
        LoadTextureFlyEnemy(flyEnemy[0]);

        //Player
        player.playerTexture = LoadTexture("resources/Sprites/Player1.png");
        secondPlayer.playerTexture = LoadTexture("resources/Sprites/Player2.png");
    }

    void InitRestartMenu()
    {
        //Restart menu
        restartMenu.width = 600;
        restartMenu.height = 500;
        restartMenu.pos.x = static_cast<float>(screenWidth / 4.3);
        restartMenu.pos.y = static_cast<float>(screenHeight / 4.5);
        restartMenu.isActive = false;
        restartMenu.texture = LoadTexture("resources/Sprites/RestartGameMenu.png");

        //Restart Button
        restartButton.width = static_cast<float>(screenWidth / 2.15);
        restartButton.height = static_cast<float>(screenHeight / 2.1);
        restartButton.size = 40;
        restartButton.color = BLACK;

        //Menu Button
        returnMenuButton.width = static_cast<float>(screenWidth / 2.05);
        returnMenuButton.height = static_cast<float>(screenHeight / 1.65);
        returnMenuButton.size = 40;
        returnMenuButton.color = BLACK;

        //Quit Button
        quitGameButton.width = static_cast<float>(screenWidth / 2.03);
        quitGameButton.height = static_cast<float>(screenHeight / 1.37);
        quitGameButton.size = 40;
        quitGameButton.color = BLACK;
    }

    void InitPauseMenu()
    {
        //Pause Menu
        pauseMenu.width = 600;
        pauseMenu.height = 500;
        pauseMenu.pos.x = static_cast<float>(screenWidth / 4.5);
        pauseMenu.pos.y = static_cast<float>(screenHeight / 4.5);
        pauseMenu.isActive = false;
        pauseMenu.texture = LoadTexture("resources/Sprites/RestartGameMenu.png");

        //Pause Button Off
        pauseButtonOff.pos.x = static_cast<float>(screenWidth / 1.2);
        pauseButtonOff.pos.y = static_cast<float>(screenHeight / 20);
        pauseButtonOff.width = 64;
        pauseButtonOff.height = 64;
        pauseButtonOff.color = WHITE;
        pauseButtonOff.texture = LoadTexture("resources/Sprites/PauseButtonOff.png");

        //Pause Button On
        pauseButtonOn.pos.x = static_cast<float>(screenWidth / 1.2);
        pauseButtonOn.pos.y = static_cast<float>(screenHeight / 20);
        pauseButtonOn.width = 64;
        pauseButtonOn.height = 64;
        pauseButtonOn.color = WHITE;
        pauseButtonOn.texture = LoadTexture("resources/Sprites/PauseButtonOn.png");

        //Resume Button
        resumeButton.width = static_cast<float>(screenWidth / 2.15);
        resumeButton.height = static_cast<float>(screenHeight / 2.1);
        resumeButton.size = 40;
        resumeButton.color = BLACK;
    }

    void SubMenusInputs(bool& gameOn)
    {
        if (restartMenu.isActive)
        {
            pause = true;

            //Restart Button
            if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.5), static_cast<float>(screenHeight / 2.2), static_cast<float>(screenWidth / 4), static_cast<float>(screenHeight / 10) }))
            {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                    RestartGame();
                }
            }

            //Return Menu Button
            if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.5), static_cast<float>(screenHeight / 1.7), static_cast<float>(screenWidth / 4), static_cast<float>(screenHeight / 12) }))
            {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                    RestartGame();
                    restartMenu.isActive = false;
                    playGame = false;
                    optionSelect = 0;
                }
            }

            //Quit Game Button
            if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.5), static_cast<float>(screenHeight / 1.4), static_cast<float>(screenWidth / 4), static_cast<float>(screenHeight / 12) }))
            {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                    gameOn = false;
                }
            }
        }

        if (pauseMenu.isActive)
        {
            //Resume Button
            if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.5), static_cast<float>(screenHeight / 2.2), static_cast<float>(screenWidth / 4), static_cast<float>(screenHeight / 10) }))
            {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                    pause = false;
                    pauseMenu.isActive = false;
                }
            }

            //Return Menu Button
            if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.5), static_cast<float>(screenHeight / 1.7), static_cast<float>(screenWidth / 4), static_cast<float>(screenHeight / 12) }))
            {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                    RestartGame();
                    pause = false;
                    playGame = false;
                    pauseMenu.isActive = false;
                    optionSelect = 0;
                }
            }

            //Quit Game Button
            if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.5), static_cast<float>(screenHeight / 1.4), static_cast<float>(screenWidth / 4), static_cast<float>(screenHeight / 12) }))
            {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                    gameOn = false;
                }
            }
        }

        if (!restartMenu.isActive && !pauseMenu.isActive)
        {
            if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_P))
            {
                pauseMenu.isActive = true;
                pause = true;
            }

            if (CheckCollisionPointRec(mouse.position, Rectangle{ pauseButtonOff.pos.x, pauseButtonOff.pos.y, pauseButtonOff.width, pauseButtonOff.height }))
            {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    pauseMenu.isActive = true;
                    pause = true;
                }
            }
        }

        else
        {
            if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_P))
            {
                pauseMenu.isActive = false;
                pause = false;
                HideCursor();
            }

            if (CheckCollisionPointRec(mouse.position, Rectangle{ pauseButtonOn.pos.x, pauseButtonOn.pos.y, pauseButtonOn.width, pauseButtonOn.height }))
            {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    pauseMenu.isActive = false;
                    pause = false;
                    HideCursor();
                }
            }
        }
    }

    void GameLoop()
    {
        HideCursor();
        bool gameOn = true;
        
        if (gameOn == true)
        {
            while (!WindowShouldClose() && gameOn)
            {
                MouseMovement();
                MenuCollisions(mouse, optionSelect);
                MenuInputs(mouse, optionSelect, playGame, coop);

                if (playGame == true)
                {
                    SubMenusInputs(gameOn);

                    if (!pause)
                    {
                        Update();
                        Collisions();
                    }

                    PauseMenuCollisions();
                    RestarGameMenuCollisions();
                }
                
                if (screenWidth == 1024 && screenHeight == 768)
                {
                    switch (optionSelect)
                    {
                        case static_cast<int>(Menu::MainMenu) :
                            BeginDrawing();
                            ClearBackground(BLACK);
                            DrawMenu(gameFont);
                            DrawMouse(mouse);
                            EndDrawing();
                            break;

                        case static_cast<int>(Menu::Play) :
                            Draw();
                            break;

                        case static_cast<int>(Menu::Controls) :
                            BeginDrawing();
                            ClearBackground(BLACK);
                            DrawControls(gameFont);
                            DrawMouse(mouse);
                            EndDrawing();
                            break;

                        case static_cast<int>(Menu::Rules) :
                            BeginDrawing();
                            ClearBackground(BLACK);
                            DrawRules(gameFont);
                            DrawMouse(mouse);
                            EndDrawing();
                            break;

                        case static_cast<int>(Menu::Credits) :
                            BeginDrawing();
                            ClearBackground(BLACK);
                            DrawCredits(gameFont);
                            DrawMouse(mouse);
                            EndDrawing();
                            break;

                        case static_cast<int>(Menu::Quit) :
                            gameOn = false;
                            break;

                        case static_cast<int>(Menu::PlayMenu):
                            BeginDrawing();
                            ClearBackground(BLACK);
                            DrawPlayMenu(gameFont, player, secondPlayer);
                            DrawMouse(mouse);
                            EndDrawing();
                            break;
                    }
                }
            }
        }
        
        if (!gameOn)
        {
            UnloadData();
            CloseWindow();
        }
    }

    void Update()
    {
        ObstacleMovement();

        PlayerMovement();

        for (int i = 0; i < maxBullets; i++)
        {
            PlayerBulletMovement(playerBullet[i], player, 13);
        }

        if (coop)
        {
            for (int i = 0; i < maxBullets2; i++)
            {
                PlayerBulletMovement(player2Bullet[i], secondPlayer, 9);
            }
        }

        BackgroundMovement();
        FlyEnemyMovement();
    }

    void Draw()
    {
        BeginDrawing();

        ClearBackground(BLACK);
        
        DrawBackground(sky);
        DrawBackground(sky2);
        
        DrawBackground(city);
        DrawBackground(city2);
        
        DrawBackground(hill);
        DrawBackground(hill2);
        
        DrawObstacle(obstacle);
        
        for (int i = 0; i < maxBullets; i++)
        {
            DrawBullet(playerBullet[i]);
        }

        for (int i = 0; i < maxflyEnemy; i++)
        {
            if (flyEnemy[i].isActive == true)
            {
                DrawFlyEnemy(flyEnemy[i]);
            }
        }

        DrawPlayer(player);
        DrawTextEx(gameFont, TextFormat("score %0i", player.points), { static_cast<float>(GetScreenWidth() / 2.5) , static_cast<float>(GetScreenHeight() / 1.1) }, 50, 0, WHITE);

        if (!pauseMenu.isActive)
        {
            DrawRectangle(static_cast<int>(pauseButtonOff.pos.x), static_cast<int>(pauseButtonOff.pos.y), static_cast<int>(pauseButtonOff.width), static_cast<int>(pauseButtonOff.height), BLANK);
            DrawTexture(pauseButtonOff.texture, static_cast<int>(pauseButtonOff.pos.x), static_cast<int>(pauseButtonOff.pos.y), pauseButtonOff.color);
        }

        if (pauseMenu.isActive)
        {
            DrawRectangle(static_cast<int>(pauseButtonOff.pos.x), static_cast<int>(pauseButtonOff.pos.y), static_cast<int>(pauseButtonOff.width), static_cast<int>(pauseButtonOff.height), BLANK);
            DrawTexture(pauseButtonOn.texture, static_cast<int>(pauseButtonOn.pos.x), static_cast<int>(pauseButtonOn.pos.y), pauseButtonOn.color);

            DrawPauseMenu();
        }

        if (!IsAlive(player) || PlayerWin(player))
        {
            DrawRestartGameMenu();
        }

        DrawMouse(mouse);

        EndDrawing();
    }

    void Collisions()
    {
        PlayerCollision(player);

        if (coop)
        {
            PlayerCollision(secondPlayer);
        }

        for (int i = 0; i < maxBullets; i++)
        {
            BulletCollision(playerBullet[i]);
        }

        if (coop)
        {
            for (int i = 0; i < maxBullets2; i++)
            {
                BulletCollision(player2Bullet[i]);
            }
        }
        
        for (int i = 0; i < maxBullets; i++)
        {
            BulletCollisonLimit(playerBullet[i]);
        }

        if (coop)
        {
            for (int i = 0; i < maxBullets2; i++)
            {
                BulletCollisonLimit(player2Bullet[i]);
            }
        }

        FlyEnemyCollisionLimit();
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
        if (IsKeyDown(KEY_A))
        {
            player.pos.x -= player.speed * GetFrameTime();
        }

        if (IsKeyDown(KEY_D))
        {
            player.pos.x += player.speed * GetFrameTime();
        }

        if (IsKeyDown(KEY_SPACE) && player.isJumping == false)
        {
            PlayerJump(player);
        }
        if (player.isJumping == true && player.pos.y < ground.pos.y)
        {
            player.gravity = player.gravity + player.jumpForce * GetFrameTime();
            player.pos.y = player.pos.y + player.gravity * GetFrameTime();
        }
        if (player.isJumping == false)
        {
            player.speed = 420;
        }

        if (IsKeyPressed(KEY_W))
        {
            for (int i = 0; i < maxBullets; i++)
            {
                if (playerBullet[i].isActive == false)
                {
                    if (!playerBullet[i].isMoving)
                    {
                        playerBullet[i].isActive = true;
                        playerBullet[i].isMoving = true;

                        break;
                    }
                }
            }
        }
        
        PlayerLimit(player, screenWidth);

        if (coop)
        {
            if (IsKeyDown(KEY_LEFT))
            {
                secondPlayer.pos.x -= secondPlayer.speed * GetFrameTime();
            }

            if (IsKeyDown(KEY_RIGHT))
            {
                secondPlayer.pos.x += secondPlayer.speed * GetFrameTime();
            }

            if (IsKeyDown(KEY_DOWN) && secondPlayer.isJumping == false)
            {
                PlayerJump(secondPlayer);
            }
            if (secondPlayer.isJumping == true && secondPlayer.pos.y < ground.pos.y)
            {
                secondPlayer.gravity = secondPlayer.gravity + secondPlayer.jumpForce * GetFrameTime();
                secondPlayer.pos.y = secondPlayer.pos.y + secondPlayer.gravity * GetFrameTime();
            }
            if (secondPlayer.isJumping == false)
            {
                secondPlayer.speed = 420;
            }

            if (IsKeyPressed(KEY_UP))
            {
                for (int i = 0; i < maxBullets; i++)
                {
                    if (playerBullet[i].isActive == false)
                    {
                        if (!playerBullet[i].isMoving)
                        {
                            playerBullet[i].isActive = true;
                            playerBullet[i].isMoving = true;

                            break;
                        }
                    }
                }
            }

            PlayerLimit(secondPlayer, screenWidth);
        }
    }

    void PlayerJump(Player& play)
    {
        int minimumHeightForPlayer = 650;

        play.gravity = -250;
        
        if (play.pos.y < minimumHeightForPlayer)
        {
            play.isJumping = true;
            play.speed = 250;
            //aca va el sonido sino se ejecuta mil veces
        }

        play.pos.y += play.gravity * GetFrameTime();
    }

    void PlayerBulletMovement(Bullet& playerbullet, Player& play, int bulletPos)
    {
        for (int i = 0; i < maxBullets; i++)
        {
            if (playerbullet.isMoving == false)
            {
                playerbullet.pos.y = play.pos.y;
                playerbullet.pos.x = play.pos.x + bulletPos;
            }
            if (playerbullet.isMoving)
            {
                playerbullet.pos.y -= playerbullet.speed * GetFrameTime();
            }
        }
    }

    void BulletCollision(Bullet& playerbullet)
    {
        for(int j = 0; j < maxflyEnemy; j++)
        {
            if (CheckCollisionRecRec(playerbullet.pos, playerbullet.width, playerbullet.height, flyEnemy[j].pos, flyEnemy[j].width, flyEnemy[j].height))
            {
                playerbullet.isMoving = false;
                playerbullet.isActive = false;

                flyEnemy[j].life--;
            }
            if (flyEnemy[j].life <= 0)
            {
                flyEnemy[j].isActive = false;
                player.points = player.points + 50;
                FlyEnemyRespawn();
            }
        }
    }

    void BulletCollisonLimit(Bullet& playerbullet)
    {
        if (playerbullet.isMoving)
        {
            if (playerbullet.pos.y < 0)
            {
                playerbullet.isMoving = false;
                playerbullet.isActive = false;
            }
            if (playerbullet.pos.y >= screenHeight)
            {
                playerbullet.isMoving = false;
                playerbullet.isActive = false;
            }
        }
    }

    void FlyEnemyMovement()
    {
        int maxLim = 300;
        int minLim = 15;
        int mov = 5;

        for (int i = 0;  i < maxflyEnemy; i++)
        {
            if (flyEnemy[i].isMoving == true)
            {
                if (flyEnemy[i].moveDown == false)
                {
                    flyEnemy[i].pos.x += flyEnemy[i].speed * GetFrameTime();
                    flyEnemy[i].pos.y += sin(flyEnemy[i].speed * GetFrameTime()) * mov;

                    if (flyEnemy[i].pos.y > maxLim)
                    {
                        flyEnemy[i].moveDown = true;
                    }
                }

                if (flyEnemy[i].moveDown == true)
                {
                    flyEnemy[i].pos.x += flyEnemy[i].speed * GetFrameTime();
                    flyEnemy[i].pos.y -= sin(flyEnemy[i].speed * GetFrameTime()) * mov;

                    if (flyEnemy[i].pos.y < minLim)
                    {
                        flyEnemy[i].moveDown = false;
                    }
                }
            }
        }
    }

    void FlyEnemyCollisionLimit()
    {
        for (int i = 0; i < maxflyEnemy; i++)
        {
            if (flyEnemy[i].isMoving)
            {
                if (flyEnemy[i].pos.x >= screenWidth + flyEnemy[i].width)
                {
                    flyEnemy[i].pos.x = static_cast<float>(screenWidth / -2.5);
                    flyEnemy[i].pos.y = static_cast<float>(screenHeight / -2.5);
                }
            }
        }
    }

    void FlyEnemyRespawn()
    {
        for (int i = 0; i < maxflyEnemy; i++)
        {
            if (flyEnemy[i].isActive == false)
            {
                flyEnemy[i].pos.x = static_cast<float>(screenWidth / -1.13);
                flyEnemy[i].pos.y = static_cast<float>(screenHeight / -1.13);

                flyEnemy[i].life = 2;
                flyEnemy[i].isActive = true;
            }
        }
    }

    void PlayerCollision(Player& play)
    {
        if (CheckCollisionRecRec(play.pos, play.width - 20, play.height - 5, obstacle.pos, obstacle.width, obstacle.height))
        {
            play.isCollision = true;
            LoseLife(play);
        }

        if (CheckCollisionRecRec(play.pos, play.width, play.height, ground.pos, ground.width , ground.height))
        {
            play.isJumping = false;
            play.gravity = 0;
        }
    }

    void ObstacleMovement()
    {
        obstacle.pos.x -= obstacle.speed * GetFrameTime();

        ObstacleTeleport();
    }

    void ObstacleTeleport()
    {
        if (obstacle.pos.x > screenWidth - obstacle.width)
        {
            obstacle.pos.x = static_cast<float>(screenWidth / screenWidth);
        }

        if (obstacle.pos.x < screenWidth / screenWidth - obstacle.width)
        {
            player.points = player.points + 25;
            obstacle.pos.x = screenWidth - obstacle.width;
        }
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

        hill.pos.x -= hill.speed * GetFrameTime();
        hill2.pos.x -= hill2.speed * GetFrameTime();

        BackgroundParallax(sky, screenWidth);
        BackgroundParallax(sky2, screenWidth);
        
        BackgroundParallax(city, screenWidth);
        BackgroundParallax(city2, screenWidth);
        
        BackgroundParallax(hill, screenWidth);
        BackgroundParallax(hill2, screenWidth);
    }

    void DrawPauseMenu()
    {
        DrawRectangle(static_cast<int>(restartMenu.pos.x), static_cast<int>(restartMenu.pos.y), static_cast<int>(restartMenu.width), static_cast<int>(restartMenu.height), BLANK);
        DrawTexture(restartMenu.texture, static_cast<int>(restartMenu.pos.x), static_cast<int>(restartMenu.pos.y), WHITE);

        DrawTextEx(gameFont, "PAUSE", { static_cast<float>(screenWidth / 2.5), static_cast<float>(screenHeight / 3.1) }, 100, 0, WHITE);

        //Restart Button
        DrawRectangle(static_cast<int>(screenWidth / 2.2), static_cast<int>(screenHeight / 2.2), static_cast<int>(screenWidth / 6.5), static_cast<int>(screenHeight / 10), BLANK);
        DrawTextEx(gameFont, "RESUME", { static_cast<float>(resumeButton.width), static_cast<float>(resumeButton.height) }, static_cast<float>(resumeButton.size), 0, resumeButton.color);

        //Return Menu Button
        DrawRectangle(static_cast<int>(screenWidth / 2.07), static_cast<int>(screenHeight / 1.7), static_cast<int>(screenWidth / 9.5), static_cast<int>(screenHeight / 12), BLANK);
        DrawTextEx(gameFont, "MENU", { static_cast<float>(returnMenuButton.width), static_cast<float>(returnMenuButton.height) }, static_cast<float>(returnMenuButton.size), 0, returnMenuButton.color);

        //Quit Game Button
        DrawRectangle(static_cast<int>(screenWidth / 2.07), static_cast<int>(screenHeight / 1.4), static_cast<int>(screenWidth / 10), static_cast<int>(screenHeight / 12), BLANK);
        DrawTextEx(gameFont, "QUIT", { static_cast<float>(quitGameButton.width), static_cast<float>(quitGameButton.height) }, static_cast<float>(quitGameButton.size), 0, quitGameButton.color);
    }

    void PauseMenuCollisions()
    {
        if (pauseMenu.isActive)
        {
            //Restart Button
            if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.2), static_cast<float>(screenHeight / 2.2), static_cast<float>(screenWidth / 6.5), static_cast<float>(screenHeight / 10) }))
            {
                resumeButton.color = BLUE;
            }

            else
            {
                resumeButton.color = WHITE;
            }

            //Return Menu Button
            if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.07), static_cast<float>(screenHeight / 1.7), static_cast<float>(screenWidth / 9.5), static_cast<float>(screenHeight / 12) }))
            {
                returnMenuButton.color = BLUE;
            }

            else
            {
                returnMenuButton.color = WHITE;
            }

            //Quit Game Button
            if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.07), static_cast<float>(screenHeight / 1.4), static_cast<float>(screenWidth / 10), static_cast<float>(screenHeight / 12) }))
            {
                quitGameButton.color = BLUE;
            }

            else
            {
                quitGameButton.color = WHITE;
            }
        }
    }

    void DrawRestartGameMenu()
    {
        DrawRectangle(static_cast<int>(restartMenu.pos.x), static_cast<int>(restartMenu.pos.y), static_cast<int>(restartMenu.width), static_cast<int>(restartMenu.height), BLANK);
        restartMenu.isActive = true;

        DrawTexture(restartMenu.texture, static_cast<int>(restartMenu.pos.x), static_cast<int>(restartMenu.pos.y), WHITE);

        if (!IsAlive(player))
        {
            DrawTextEx(gameFont, "YOU LOSE", { static_cast<float>(screenWidth / 3), static_cast<float>(screenHeight / 3.1) }, 100, 0, WHITE);
        }

        if (PlayerWin(player))
        {
            DrawTextEx(gameFont, "YOU WIN", { static_cast<float>(screenWidth / 3), static_cast<float>(screenHeight / 3.1) }, 100, 0, WHITE);
        }

        //Restart Button
        DrawRectangle(static_cast<int>(screenWidth / 2.2), static_cast<int>(screenHeight / 2.2), static_cast<int>(screenWidth / 6.2), static_cast<int>(screenHeight / 10), BLANK);
        DrawTextEx(gameFont, "RESTART", { static_cast<float>(restartButton.width), static_cast<float>(restartButton.height) }, static_cast<float>(restartButton.size), 0, restartButton.color);


        //Return Menu Button
        DrawRectangle(static_cast<int>(screenWidth / 2.07), static_cast<int>(screenHeight / 1.7), static_cast<int>(screenWidth / 9.5), static_cast<int>(screenHeight / 12), BLANK);
        DrawTextEx(gameFont, "MENU", { static_cast<float>(returnMenuButton.width), static_cast<float>(returnMenuButton.height) }, static_cast<float>(returnMenuButton.size), 0, returnMenuButton.color);

        //Quit Game Button
        DrawRectangle(static_cast<int>(screenWidth / 2.07), static_cast<int>(screenHeight / 1.4), static_cast<int>(screenWidth / 10), static_cast<int>(screenHeight / 12), BLANK);
        DrawTextEx(gameFont, "QUIT", { static_cast<float>(quitGameButton.width), static_cast<float>(quitGameButton.height) }, static_cast<float>(quitGameButton.size), 0, quitGameButton.color);
    }

    void RestarGameMenuCollisions()
    {
        if (restartMenu.isActive)
        {
            //Restart Button
            if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.2), static_cast<float>(screenHeight / 2.2), static_cast<float>(screenWidth / 6.2), static_cast<float>(screenHeight / 10) }))
            {
                restartButton.color = BLUE;
            }

            else
            {
                restartButton.color = WHITE;
            }

            //Return Menu Button
            if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.07), static_cast<float>(screenHeight / 1.7), static_cast<float>(screenWidth / 9.5), static_cast<float>(screenHeight / 12) }))
            {
                returnMenuButton.color = BLUE;
            }

            else
            {
                returnMenuButton.color = WHITE;
            }

            //Quit Game Button
            if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.07), static_cast<float>(screenHeight / 1.4), static_cast<float>(screenWidth / 10), static_cast<float>(screenHeight / 12) }))
            {
                quitGameButton.color = BLUE;
            }

            else
            {
                quitGameButton.color = WHITE;
            }
        }
    }

    void RestartGame()
    {
        //Player
        player.pos.x = static_cast<float>(screenWidth / 6);
        player.pos.y = static_cast<float>(screenHeight / 1.165);
        player.width = 80;
        player.height = 40;
        player.speed = 420;
        player.lifes = 3;
        player.points = 0;
        player.isCollision = false;
        player.isAlive = true;
        player.win = false;

        //Second Player
        secondPlayer.pos.x = static_cast<float>(screenWidth / 6);
        secondPlayer.pos.y = static_cast<float>(screenHeight / 1.165);
        secondPlayer.width = 80;
        secondPlayer.height = 40;
        secondPlayer.speed = 420;
        secondPlayer.lifes = 3;
        secondPlayer.isCollision = false;
        secondPlayer.isAlive = true;
        secondPlayer.win = false;

        //Bullet
        //PlayerBullets
        for (int i = 0; i < maxBullets; i++)
        {
            playerBullet[i].isActive = false;
            playerBullet[i].isMoving = false;
            playerBullet[i].pos.y = player.pos.y;
            playerBullet[i].pos.x = player.pos.x;
        }

        //Bullet
        //Second Player Bullets
        for (int i = 0; i < maxBullets2; i++)
        {
            player2Bullet[i].isActive = false;
            player2Bullet[i].isMoving = false;
            player2Bullet[i].pos.y = secondPlayer.pos.y;
            player2Bullet[i].pos.x = secondPlayer.pos.x;
        }

        //Obstacle
        obstacle.pos.x = static_cast<float>(screenWidth - 30);
        obstacle.pos.y = static_cast<float>(screenHeight / 1.2);
        obstacle.width = 30;
        obstacle.height = 60;
        obstacle.speed = 400;

        //Ground
        ground.pos.x = static_cast<float>(screenWidth / screenWidth);
        ground.pos.y = static_cast<float>(screenHeight / 1.1);
        ground.width = static_cast<float>(screenWidth);
        ground.height = 70;

        //Mouse
        mouse.position.x = 0;
        mouse.position.y = 0;
        mouse.width = 20.0f;
        mouse.height = 20.0f;
        mouse.mouseRec = GetRecMouse(mouse);

        //Background
           //Sky
        sky.pos.x = static_cast<float>(screenWidth / screenWidth);

        sky2.pos.x = static_cast<float>(screenWidth / screenWidth + sky.width);

            //City
        city.pos.x = static_cast<float>(screenWidth / screenWidth);
        city.pos.y = static_cast<float>((screenHeight / screenHeight) - 60);
        city.speed = 200;

        city2.pos.x = static_cast<float>(screenWidth / screenWidth + city.width);
        city2.pos.y = static_cast<float>((screenHeight / screenHeight) - 60);
        city2.speed = 200;

            //Hill
        hill.pos.x = static_cast<float>(screenWidth / screenWidth);
        hill.pos.y = static_cast<float>((screenHeight / 1.28));
        hill.speed = 400;

        hill2.pos.x = static_cast<float>(screenWidth / screenWidth + hill.width);
        hill2.pos.y = static_cast<float>((screenHeight / 1.28));
        hill2.speed = 400;

        //FlyEnemy 

        for (int i = 0; i < maxflyEnemy; i++)
        {
            flyEnemy[0].pos.x = static_cast<float>(screenWidth / -2.5);
            flyEnemy[0].pos.y = static_cast<float>(screenHeight / -2.5);

            flyEnemy[1].pos.x = static_cast<float>(screenWidth / -1.9);
            flyEnemy[1].pos.y = static_cast<float>(screenHeight / -1.9);

            flyEnemy[2].pos.x = static_cast<float>(screenWidth / -1.5);
            flyEnemy[2].pos.y = static_cast<float>(screenHeight / -1.5);

            flyEnemy[3].pos.x = static_cast<float>(screenWidth / -1.22);
            flyEnemy[3].pos.y = static_cast<float>(screenHeight / -1.22);

            flyEnemy[4].pos.x = static_cast<float>(screenWidth / -1.05);
            flyEnemy[4].pos.y = static_cast<float>(screenHeight / -1.05);
        }

        //RestartMenu
        restartMenu.isActive = false;
        pause = false;
    }

    void UnloadData()
    {
        UnloadFont(gameFont);
        
        UnloadTexture(mouse.mouseTexture);

        UnloadTexture(sky.tex);
        UnloadTexture(sky2.tex);
        
        UnloadTexture(city.tex);
        UnloadTexture(city2.tex);

        UnloadTexture(hill.tex);
        UnloadTexture(hill2.tex);

        UnloadTexture(restartMenu.texture);
        UnloadTexture(pauseMenu.texture);
        UnloadTexture(pauseButtonOff.texture);
        UnloadTexture(pauseButtonOn.texture);

        UnloadTexture(player.playerTexture);
        
        UnloadTextureBullet(playerBullet[0]);
        UnloadTextureFlyEnemy(flyEnemy[0]);
    }
}