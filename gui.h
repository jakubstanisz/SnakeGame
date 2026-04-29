#pragma once
#include "raylib.h"
#include "food.h"
#include "snake.h"

class Gui{
public:
    int screenWidth;
    int screenHeight;
    
    Gui(int screenWidth, int screenHeight);
    void Display();
};