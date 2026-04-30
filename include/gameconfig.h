#pragma once
class GameConfig{
private:
    const int screenWidth;
    const int screenHeight;
public:
    GameConfig(int screenWidth, int screenHeight);
    int getScreenWidth();
    int getScreenHeight();
};