#pragma once
class GameConfig{
private:
    int screenWidth;
    int screenHeight;
public:
    GameConfig(int screenWidth, int screenHeight);
    int getScreenWidth();
    int getScreenHeight();
};