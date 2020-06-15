#include "Texture.h"
#include "AssetsLoader.h"
#include "Window.h"
#include "Renderer.h"
#include "SDLHandler.h"
#include "Sound.h"
#include "PlayerGraphic.h"
#include <iostream>

#define WALK_DISTANCE 30

int main(int argc, char* argv[]){
    SDLHandler sdlH = SDLHandler(AUDIO | VIDEO | TIMER | EVENTS);
    
    sdlH.initializeMixer();
    sdlH.initializeImage();
    sdlH.initializeTTF();
    sdlH.setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    
    Window window("Ventana prueba", 600, 600);
    Renderer& renderer = window.getRenderer();

    renderer.setDrawColor(200,255,255,255);
	renderer.clear();

    Texture people(renderer);
    people.loadFromFile("dot.bmp", true, {0, 255, 255});

    AssetsLoader assets(renderer);
    //Texture& texture = assets.getTexture(0);

    PlayerGraphic player(assets);

    SDL_Event event;
    bool quit = false;
    int y = 50;
    int moveSpeed = 5;
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
                    y -= moveSpeed;
                    break;

                    case SDLK_DOWN:
                    y += moveSpeed;
                    break;

                    case SDLK_LEFT:
                    player.moveRight(-WALK_DISTANCE);
                    break;

                    case SDLK_RIGHT:
                    player.moveRight(WALK_DISTANCE);
                    break;

                    default:
                    break;
                }
            }
            
            else if (event.type == SDL_WINDOWEVENT)
                continue;
            
            SDL_FlushEvent(SDL_KEYDOWN);
            for (int i = 0; i < 10; i++){
                renderer.clear();
                player.render(i);
                renderer.renderPresent();
                SDL_Delay(30);
            }
            player.idle();   
        }
    }
     
}
