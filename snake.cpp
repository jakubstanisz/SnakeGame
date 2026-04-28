#include "snake.h"
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

void Snake::Update(){
    Vector2 newHead = body.front();
    //obliczanie nowej pozycji
    newHead.x += direction.x * 50;
    newHead.y += direction.y * 50;
    body.push_front(newHead);

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
