#include "Primitive.h"
#include <iostream>

namespace Primitive
{

Primitive::Triangle::Triangle()
{
    // Set shape verticies
    this->verticies[0] = SDL_Vertex{ SDL_FPoint{ 300, 100 }, SDL_Color{ 255, 0, 0, 255 }, SDL_FPoint{ 0 }, };
    this->verticies[1] = SDL_Vertex{ SDL_FPoint{ 100, 500 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, };
    this->verticies[2] = SDL_Vertex{ SDL_FPoint{ 500, 500 }, SDL_Color{ 0, 0, 255, 255 }, SDL_FPoint{ 0 }, };
    
    // Set size of verticies
    this->vSize = sizeof(this->verticies) / sizeof(this->verticies[0]);
}

void Primitive::Triangle::translate(float x, float y)
{
    for (int i = 0; i < this->vSize; i++)
    {
        this->verticies[i].position.x += x;
        this->verticies[i].position.y += y;
    }
    std::cout << this->verticies[0].position.x << std::endl;
    std::cout << this->getVerticies()[0].position.x << std::endl;
}

SDL_Vertex* Primitive::Triangle::getVerticies()
{
    return this->verticies;
}
}
