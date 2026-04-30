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
    // calculating new position of a snake head
    newHead.x += direction.x * 50;
    newHead.y += direction.y * 50;
    // checking if snake is out of the map, if true it resets game
    if (newHead.x < 0 || newHead.x > config.getScreenWidth() 
        || newHead.y < 0 || newHead.y > config.getScreenHeight()){
        body.clear();
    }
    body.push_front(newHead);
    if (food.position.x == newHead.x && food.position.y == newHead.y){
        addSegment = true;
        food.Spawn(config);
    }

    if (addSegment){
        //set on false to prevent infinity snake growth
        addSegment = false;
    } else {
        // clearing snake back to remain the same snake length
        body.pop_back();
    }
}
void Snake::Reset(){
    body.clear();
}
