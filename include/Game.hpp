#pragma once
#include <stdio.h>
#include <SDL.h>

#include "entt.hpp"
#include "imgui.h"
#include "imgui_sdl.h"

class Game
{
public:
    Game(const char* title,int w,int h);
    ~Game();
    void start();
    void init();
    void update();
    void render();
    void handleEvent(SDL_Event* e);
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event e;
    bool isRunning = false;
    entt::registry m;
    SDL_Texture* texture;
};