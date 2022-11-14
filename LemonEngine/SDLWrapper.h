#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "Primitive.h"

class Application
{
public:
    Application();
    void UpdateLoop();
    void AddSceneObject(Primitive::Triangle* object);
    void Destroy();
    bool PollEvents(SDL_Event* event);
public:
    SDL_Window* window;
    SDL_Renderer* renderer;
private:
    std::vector<Primitive::Triangle*> sceneObjects;


};
