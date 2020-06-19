#include "Client.h"
#include "Renderer.h"
#include "Sound.h"
#include "Screen.h"
#include "Window.h"
#include "PlayerGraphic.h"
#include "MapGraphic.h"
#include "Texture.h"
#include "AssetsLoader.h"
#include "Configuration.h"
#include "Clock.h"
#include <chrono>
#include <iostream>
#include <unistd.h>

#define WALK_DISTANCE 64

Client::Client(Window& window): communicator(Communicator(*this)), window(window){

}

void Client::run(){
    Renderer& renderer = window.getRenderer();
    Configuration& config = Configuration::getInstance();

    int microsecondsPerFrame = 1000000 / config.getValue("fps");

    renderer.setDrawColor(200, 255, 255, 255);
	renderer.clear();

    AssetsLoader assets(renderer);

    Texture people(renderer);
    people.loadFromFile("images/dot.bmp", true, {0, 255, 255});

    MapGraphic map("hola.json", assets, 25, 25);

    Screen background("images/bg.png", renderer, config.getValue("window_width"), config.getValue("window_height"), map);
    background.moveToCenter();
    
    PlayerGraphic player(assets, 20, 14);      

    SDL_Event event;
    bool quit = false;

    Clock clock;

    while (!quit){
        clock.start();

        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT){
            quit = true;
            break;
        }
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
                continue;
                break;
            }
        }
        
        SDL_FlushEvent(SDL_KEYDOWN);

        renderer.clear();
        background.centerToPosition(player.getX(), player.getY());
        background.render(); 
        player.render(background);

        renderer.renderPresent();        

        clock.stop();
        int elapsedTime = clock.getDuration();        
        int waitTime = microsecondsPerFrame - elapsedTime;

        if (waitTime > 0)
            usleep(waitTime);
    }
}