#include "Game.hpp"

void MySaveFunction();

Game::Game(const char* title,int w,int h)
{
    window = SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,w,h,0);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
}

void Game::start()
{
    isRunning = true;
    init();
    while (isRunning)
    {
        handleEvent(&e);
        update();
        render();
    }
}

void Game::init()
{
    ImGui::CreateContext();
	ImGuiSDL::Initialize(renderer, 640, 480);

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, 100, 100);
	{
		SDL_SetRenderTarget(renderer, texture);
		SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderTarget(renderer, nullptr);
	}
}

void Game::update()
{
    ImGuiIO& io = ImGui::GetIO();

    int mouseX, mouseY;
    const int buttons = SDL_GetMouseState(&mouseX, &mouseY);
    
    io.DeltaTime = 1.0f / 60.0f;
    io.MousePos = ImVec2(static_cast<float>(mouseX), static_cast<float>(mouseY));
    io.MouseDown[0] = buttons & SDL_BUTTON(SDL_BUTTON_LEFT);
    io.MouseDown[1] = buttons & SDL_BUTTON(SDL_BUTTON_RIGHT);
    //io.MouseWheel = static_cast<float>(wheel);s
}

void Game::render()
{
    //IMGUI
    ImGui::NewFrame();
    //IMGUI Section
    
    ImGui::EndFrame();

    //SDL
    SDL_RenderClear(renderer);

    ImGui::Render();
    ImGuiSDL::Render(ImGui::GetDrawData());

    SDL_RenderPresent(renderer);
}

void Game::handleEvent(SDL_Event* e)
{
    while(SDL_PollEvent(e) != 0)
    {
        if(e->type == SDL_QUIT)
        {
            isRunning = false;
        }
    }
}

Game::~Game()
{
    ImGuiSDL::Deinitialize();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	ImGui::DestroyContext();
}

void MySaveFunction()
{
    printf("clicked\n");
}