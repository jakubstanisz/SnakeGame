#pragma once
#include "raylib.h"
#include "gameconfig.h"
class Food {
public:
    Vector2 position;
    int size;
    Food(GameConfig &config);
    void Spawn(GameConfig &config);
    void Draw();
};