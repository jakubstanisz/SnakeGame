#include "raylib.h"
#include "food.h"
#include "snake.h"

int main() {
    const int screenWidth = 600;
    const int screenHeight = 600;
    const int gridSize = 50;

    InitWindow(screenWidth, screenHeight, "Snake Game");

    Food food;
    Snake snake;
    Color gridColor = BLACK; 
    
    double lastUpdateTime = 0;
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        int key = GetKeyPressed();

        switch (key) {
            case KEY_UP:
                snake.direction = {0, -1};
                break;
            case KEY_DOWN:
                snake.direction = {0, 1};
                break;
            case KEY_LEFT:
                snake.direction = {-1, 0};
                break;
            case KEY_RIGHT:
                snake.direction = {1, 0};
                break;
        }
        
        if (GetTime() - lastUpdateTime >= 0.2) {
            snake.Update();
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
    return 0;
}