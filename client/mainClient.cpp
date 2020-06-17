#include "Texture.h"
#include "AssetsLoader.h"
#include "Window.h"
#include "Renderer.h"
#include "SDLHandler.h"
#include "Sound.h"
#include "Screen.h"
#include "PlayerGraphic.h"
#include "MapGraphic.h"
#include <iostream>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600
#define WALK_DISTANCE 64

int main(int argc, char* argv[]){
    SDLHandler sdlH = SDLHandler(AUDIO | VIDEO | TIMER | EVENTS);
    
    sdlH.initializeMixer();
    sdlH.initializeImage();
    sdlH.initializeTTF();
    sdlH.setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    
    Window window("Ventana prueba", WINDOW_WIDTH, WINDOW_HEIGHT);
    Renderer& renderer = window.getRenderer();

    renderer.setDrawColor(200,255,255,255);
	renderer.clear();

    AssetsLoader assets(renderer);

    Texture people(renderer);
    people.loadFromFile("Images/dot.bmp", true, {0, 255, 255});

    MapGraphic map("hola.json", assets, WINDOW_HEIGHT, WINDOW_WIDTH);

    Screen background("Images/bg.png", renderer, WINDOW_WIDTH, WINDOW_HEIGHT, map);
    background.moveToCenter();

    PlayerGraphic player(assets, 24, 16);

    SDL_Event event;
    bool quit = false;

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
                    player.moveUp(WALK_DISTANCE);
                    break;

                    case SDLK_DOWN:
                    player.moveDown(WALK_DISTANCE);
                    break;

                    case SDLK_LEFT:
                    player.moveLeft(WALK_DISTANCE);
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

            for (int i = 0; i < 8; i++){
                renderer.clear();

                background.centerToPosition(player.getX(), player.getY());
                
                background.render();
                player.render(i, background);
                
                renderer.renderPresent();
                SDL_Delay(45);
            }

            player.idle();   
        }
    }

    return 0;
}

/*
int main(int argc, char* argv[]){
    SDLHandler sdlH = SDLHandler(AUDIO | VIDEO | TIMER | EVENTS);
    
    sdlH.initializeMixer();
    sdlH.initializeImage();
    sdlH.initializeTTF();
    sdlH.setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    
    Window window("Ventana prueba", WINDOW_WIDTH, WINDOW_HEIGHT);
    Renderer& renderer = window.getRenderer();

    renderer.setDrawColor(200,255,255,255);
	renderer.clear();

    Texture text(renderer);
    text.loadFromRenderedText("Hola", "Fonts/Chantelli_Antiqua.ttf", 60);

    Texture dot(renderer);
    dot.loadFromFile("Images/dot.bmp", false, {0, 255, 255});
    Screen background("Images/bg.png", renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
    background.moveToCenter();

    background.render();
    dot.render(50,50);
    text.render(50, 150);

    renderer.renderPresent();

    SDL_Delay(2000);

    //AssetsLoader assets(renderer);
    //PlayerGraphic player(assets);
    
    return 0;
}
*/