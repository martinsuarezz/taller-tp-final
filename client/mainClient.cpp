#include "Texture.h"
#include "Window.h"
#include "Renderer.h"
#include "SDLHandler.h"
#include "Sound.h"

int main(int argc, char* argv[]){
    SDLHandler sdlH = SDLHandler(AUDIO | VIDEO | TIMER | EVENTS);
    
    sdlH.initializeMixer();
    sdlH.initializeImage();
    sdlH.initializeTTF();
    sdlH.setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    
    Window window("Ventana prueba", 600, 600);
    Renderer& renderer = window.getRenderer();
    SDL_Delay(100);

    renderer.setDrawColor(255,255,255,255);
	renderer.clear();

    Texture people(renderer);
    people.loadFromFile("Images/dot.bmp", true, {0, 255, 255});

    SDL_Event event;
    bool quit = false;
    int x = 300;
    int y = 300;
    int movespeed = 5;
    while (!quit){
        while (SDL_WaitEventTimeout(&event, 500) != 0){
            if (event.type == SDL_QUIT){
                quit = true;
                break;
            }
            else if (event.type == SDL_MOUSEMOTION)
                continue;
            else if (event.type == SDL_KEYDOWN){
                switch (event.key.keysym.sym){
                    case SDLK_UP:
                    y -= movespeed;
                    break;

                    case SDLK_DOWN:
                    y += movespeed;
                    break;

                    case SDLK_LEFT:
                    x -= movespeed;
                    break;

                    case SDLK_RIGHT:
                    x += movespeed;
                    break;

                    default:
                    break;
                }
            }
            renderer.clear();
            people.render(x, y);
            renderer.renderPresent();
        }
    }   
}
