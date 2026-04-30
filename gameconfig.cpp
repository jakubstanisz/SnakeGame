#include "gameconfig.h"
GameConfig::GameConfig(int sW, int sH) 
    : screenWidth(sW), screenHeight(sH) {}
    
int GameConfig::getScreenWidth(){
    return screenWidth;
}
int GameConfig::getScreenHeight(){
    return screenHeight;
}