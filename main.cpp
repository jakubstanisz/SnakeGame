#include "gui.h"
#include "gameconfig.h"
#include <cstdlib>
#include <iostream>
/*
1. do a logic for a snake turns ( to prevent from 180 degrees movements) -- finished !!! YEAHH
2. do a logic for a snake eating --finished !!!
3. move all display logic to another gui class to take it away from main class -- finished !!! 
4. refactor directiories structure ( assets etc)
*/
int main(int argc, char *argv[]) {
    int screenWidth = 800;
    int screenHeight = 800;

    if (argc == 2) {
        screenWidth = atoi(argv[1]);
        screenHeight = atoi(argv[1]);
    } else if (argc == 3) {
        screenWidth = atoi(argv[1]);
        screenHeight = atoi(argv[2]);
    } else if (argc > 3) {
        std::cout << "Blednie podane argumenty!" << std::endl;
        return -1;
    }

    GameConfig config(screenWidth, screenHeight);
    Gui gui(config.getScreenWidth(), config.getScreenHeight());
    gui.Display(config);
    return 0;
}