#include "snake.h"
#include "food.h"
#include "gameconfig.h"
#include <raylib.h>
#define GRIDSIZE 50
Snake::Snake(){
    body.push_back(Vector2{300, 300});
}
void Snake::Draw(){
    if (body.empty()) return;

    for (auto& segment : body) {
        DrawRectangleV(segment, {50, 50}, GREEN);
    }
} 

void Snake::Update(Food& food, GameConfig &config){
    Vector2 newHead = body.front();
    //obliczanie nowej pozycji
    newHead.x += direction.x * 50;
    newHead.y += direction.y * 50;
    body.push_front(newHead);
    if (food.position.x == newHead.x && food.position.y == newHead.y){
        addSegment = true;
        food.Spawn(config);
    }

    if (addSegment){
        //resetujemy na false zeby waz nie rosl w nieskonczonosc
        addSegment = false;
    } else {
        //usuwamy dupe zeby dlugosc weza byla jednakowa
        body.pop_back();
    }
}
void Snake::Reset(){
    body.clear();
}
