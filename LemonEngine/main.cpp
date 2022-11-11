#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

class Triangle
{
private:
    SDL_Vertex verticies[3];
    int vSize;
public:
    Triangle()
    {
        // Set shape verticies
        this->verticies[0] = SDL_Vertex{ SDL_FPoint{ 300, 100 }, SDL_Color{ 255, 0, 0, 255 }, SDL_FPoint{ 0 }, };
        this->verticies[1] = SDL_Vertex{ SDL_FPoint{ 100, 500 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }, };
        this->verticies[2] = SDL_Vertex{ SDL_FPoint{ 500, 500 }, SDL_Color{ 0, 0, 255, 255 }, SDL_FPoint{ 0 }, };
        
        // Set size of verticies
        this->vSize = sizeof(this->verticies) / sizeof(this->verticies[0]);
    }
    
    
    // Returns the verticies of the shape
    SDL_Vertex* getVerticies()
    {
        return this->verticies;
    }
    
    // Translate the shape by the given values
    void translate(float x, float y)
    {
        for (int i = 0; i < this->vSize; i++)
        {
            this->verticies[i].position.x += x;
            this->verticies[i].position.y += y;
        }
    }
};

int main( int argc, char** argv )
{
    SDL_Init( SDL_INIT_EVERYTHING );
    SDL_Window* window = SDL_CreateWindow("Lemon Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN );
    SDL_Renderer* renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

    Triangle triangle;

    
    bool running = true;
    while( running )
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
                break;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                triangle.translate(10, 10);
            }
        }
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        SDL_RenderGeometry(renderer, nullptr, triangle.getVerticies(), 3, nullptr, 0);
        SDL_RenderPresent(renderer);
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
