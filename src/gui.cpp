#include "gui.h"
#include "raylib.h"
#define GRIDSIZE 50

Gui::Gui(int sW, int sH) 
    : screenWidth(sW), screenHeight(sH) {}

void Gui::Display(GameConfig &config) {
    InitWindow(screenWidth, screenHeight, "Snake Game");
    SetTargetFPS(60);

    Food food(config);
    Snake snake;
    Color gridColor = BLACK; 
    double lastUpdateTime = 0;
    
    bool gameStarted = false;

    while (!WindowShouldClose()) {
        int key = GetKeyPressed();
        Vector2 currentDirection = snake.direction;
        
        switch (key) {
            case KEY_UP: 
                if (currentDirection.y != 1) {
                    snake.direction = {0, -1};
                    gameStarted = true;
                }
                break;
            case KEY_DOWN:
                if (currentDirection.y != -1) {
                    snake.direction = {0, 1};
                    gameStarted = true;
                }
                break;
            case KEY_LEFT:
                if (currentDirection.x != 1) {
                    snake.direction = {-1, 0};
                    gameStarted = true;
                }
                break;
            case KEY_RIGHT:
                if (currentDirection.x != -1) {
                    snake.direction = {1, 0};
                    gameStarted = true;
                }
                break;
        }

        if (gameStarted) {
            if (GetTime() - lastUpdateTime >= 0.2) {
                snake.Update(food, config);
                lastUpdateTime = GetTime();
            }
        } else {
            lastUpdateTime = GetTime();
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        for (int i = 0; i <= screenWidth; i += GRIDSIZE) {
            DrawLine(i, 0, i, screenHeight, gridColor);
        }

        for (int i = 0; i <= screenHeight; i += GRIDSIZE) {
            DrawLine(0, i, screenWidth, i, gridColor);
        }

        food.Draw();
        snake.Draw();

        EndDrawing();
    }
    CloseWindow();
}