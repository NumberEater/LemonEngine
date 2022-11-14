#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include "SDLWrapper.h"
#include "Primitive.h"


int main( int argc, char** argv )
{
    Primitive::Triangle triangle;
    Application app;
    app.AddSceneObject(&triangle);

    bool running = true;
    while(running)
    {
        SDL_Event event;
        while (app.PollEvents(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
                break;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                triangle.translate(10, 10);
                //std::cout << triangle.getVerticies()[0].position.y << std::endl;
            }
        }
        app.UpdateLoop();
    }
    app.Destroy();

    return 0;
}
