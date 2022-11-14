#pragma once
#include <SDL2/SDL.h>


namespace Primitive
{

class Triangle
{
private:
    SDL_Vertex verticies[3];
    int vSize;
public:
    Triangle();
    SDL_Vertex* getVerticies();
    void translate(float x, float y);
    
};

}
