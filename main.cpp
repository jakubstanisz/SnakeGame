#include "gui.h"
#include <cstdlib>
#include <iostream>
/*
1. do a logic for a snake turns ( to prevent from 180 degrees movements) -- finished !!! YEAHH
2. do a logic for a snake eating
3. move all display logic to another gui class to take it away from main class -- finished !!! 
*/
int main(int argc, char *argv[]) {
    int screenWidth;
    int screenHeight;

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

    Gui gui(screenWidth, screenHeight);
    gui.Display();
    return 0;
}