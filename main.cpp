#include "Game.hpp"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main()
{
    Game game("Test Window",SCREEN_WIDTH,SCREEN_HEIGHT);
    game.start();
    return 0;
}
