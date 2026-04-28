#include "food.h"
#define GRIDSIZE 50
Food::Food() {
    Spawn();
}

void Food::Spawn() {
    position.x = GetRandomValue(0, 6);
    position.y = GetRandomValue(0, 6);
}

void Food::Draw() {
    DrawRectangle(position.x * GRIDSIZE, position.y * GRIDSIZE, GRIDSIZE, GRIDSIZE, BLUE);
}