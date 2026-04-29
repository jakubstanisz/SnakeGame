#include "gui.h"
#include "raylib.h"

#define gridSize 50

Gui::Gui(int sW, int sH) 
    : screenWidth(sW), screenHeight(sH) {}

void Gui::Display() {
    Food food;
    Snake snake;
    Color gridColor = BLACK; 
    double lastUpdateTime = 0;
    InitWindow(screenWidth, screenHeight, "Snake Game");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        int key = GetKeyPressed();
        Vector2 currentDirection = snake.direction;
        // if in switch is to prevent changing 
        // directions in 180 degrees i.e. from UP to DOWN in one frame
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
            snake.Update();
            lastUpdateTime = GetTime();
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        // grid Drawing 
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