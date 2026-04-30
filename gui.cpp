#include "gui.h"
#include "raylib.h"
#define gridSize 50

Gui::Gui(int sW, int sH) 
    : screenWidth(sW), screenHeight(sH) {}

void Gui::Display(GameConfig &config) {
    InitWindow(screenWidth, screenHeight, "Snake Game");
    SetTargetFPS(60);

    Food food(config);
    Snake snake;
    Color gridColor = BLACK; 
    double lastUpdateTime = 0;

    while (!WindowShouldClose()) {
        int key = GetKeyPressed();
        Vector2 currentDirection = snake.direction;
        
        switch (key) {
            case KEY_UP: 
                if (currentDirection.y != 1)
                snake.direction = {0, -1};
                break;
            case KEY_DOWN:
                if (currentDirection.y != -1)
                snake.direction = {0, 1};
                break;
            case KEY_LEFT:
                if (currentDirection.x != 1)
                snake.direction = {-1, 0};
                break;
            case KEY_RIGHT:
                if (currentDirection.x != -1) 
                snake.direction = {1, 0};
                break;
        }

        if (GetTime() - lastUpdateTime >= 0.2) {
            snake.Update(food, config);
            lastUpdateTime = GetTime();
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        for (int i = 0; i <= screenWidth; i += gridSize) {
            DrawLine(i, 0, i, screenHeight, gridColor);
        }

        for (int i = 0; i <= screenHeight; i += gridSize) {
            DrawLine(0, i, screenWidth, i, gridColor);
        }

        food.Draw();
        snake.Draw();

        EndDrawing();
    }
    CloseWindow();
}