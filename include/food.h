#pragma once
#include "raylib.h"
#include "gameconfig.h"
class Food {
private:
    Texture2D texture;
public:
    Vector2 position;
    int size;
    Food(GameConfig &config);
    ~Food();
    void Spawn(GameConfig &config);
    void Draw();
};