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
    //Snake eyes : left eye
    DrawRectangle(body.front().x + 7, body.front().y + 7, 6, 6, RED);
    DrawRectangle(body.front().x + 37, body.front().y + 7, 6, 6, RED);
    //Snake smile
    DrawRectangle(body.front().x + 7, body.front().y + 36, 36, 3, RED);
} 

void Snake::Update(Food& food, GameConfig &config){
    Vector2 newHead = body.front();
    // calculating new position of a snake head
    newHead.x += direction.x * 50;
    newHead.y += direction.y * 50;
    
    for (auto& segment : body){
        if (newHead.x == segment.x && newHead.y == segment.y){
            Reset();
            return;
        }
    }    
    // checking if snake is out of the map, if true it resets game
    if (newHead.x < 0 || newHead.x >= config.getScreenWidth() 
        || newHead.y < 0 || newHead.y >= config.getScreenHeight()){
        Reset();
        return;
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
    body.push_back(Vector2{300, 300});
    direction = {1,0};
}