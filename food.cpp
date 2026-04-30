#include "food.h"
#include "gameconfig.h"
#include <raylib.h>
#define GRIDSIZE 50

Food::Food(GameConfig& config) {
    Spawn(config);
}

void Food::Spawn(GameConfig& config) {
    int maxX = (config.getScreenWidth() / GRIDSIZE) - 1;
    int maxY = (config.getScreenHeight() / GRIDSIZE) - 1;

    position.x = GetRandomValue(0, maxX) * GRIDSIZE;
    position.y = GetRandomValue(0, maxY) * GRIDSIZE;
}

void Food::Draw() {
    Image apple = LoadImage("apple.png");
    Texture2D texture = LoadTextureFromImage(apple);
    DrawTexture(texture, position.x + 1, position.y + 1, WHITE);
}