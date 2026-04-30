#pragma once
#include <deque>
#include "gameconfig.h"
#include "raylib.h"
#include "food.h"

class Snake{
public:
    std::deque<Vector2> body;
    Vector2 direction;
    bool addSegment;

    Snake();
    void Draw();
    void Update(Food &food, GameConfig &config);
    void Reset();
};