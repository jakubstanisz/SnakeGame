#include "food.h"
#include "gameconfig.h"
#include <raylib.h>
#define GRIDSIZE 50

Food::Food(GameConfig& config) {
    //load image to ram
    Image apple = LoadImage("assets/apple.png"); 

    //load to vram
    texture = LoadTextureFromImage(apple);

    //clean from ram cuz we have it in vram
    UnloadImage(apple);
    Spawn(config);
}
Food::~Food() {
    // freeing memory in vram
    UnloadTexture(texture);
}

void Food::Spawn(GameConfig& config) {
    int maxX = (config.getScreenWidth() / GRIDSIZE) - 1;
    int maxY = (config.getScreenHeight() / GRIDSIZE) - 1;

    position.x = GetRandomValue(0, maxX) * GRIDSIZE;
    position.y = GetRandomValue(0, maxY) * GRIDSIZE;
}

void Food::Draw() {
    DrawTexture(texture, position.x + 1, position.y + 1, WHITE);
}