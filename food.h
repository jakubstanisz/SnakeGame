#pragma once
#include "raylib.h"

class Food {
public:
    Vector2 position;
    int size;

    Food();
    void Spawn();
    void Draw();
};