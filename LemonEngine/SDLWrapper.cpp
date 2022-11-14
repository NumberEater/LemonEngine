#include "SDLWrapper.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "Primitive.h"

Application::Application()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    this->window = SDL_CreateWindow("Lemon Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Application::UpdateLoop()
{
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(this->renderer);
    
    // Draw calls here
    for (int i = 0; i < this->sceneObjects.size(); i++)
    {
        SDL_RenderGeometry(this->renderer, nullptr, this->sceneObjects[i]->getVerticies(), 3, nullptr, 0);
    }
    
    SDL_RenderPresent(this->renderer);
}

void Application::AddSceneObject(Primitive::Triangle* object)
{
    this->sceneObjects.push_back(object);
}

void Application::Destroy()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

bool Application::PollEvents(SDL_Event* event)
{
    if (SDL_PollEvent(event))
        return true;
    return false;
}
