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
    int frame = 0;
    
    Renderer& renderer = window.getRenderer();
    Configuration& config = Configuration::getInstance();

    int microsecondsPerFrame = 1000000 / config.getValue("fps");

    renderer.setDrawColor(200,255,255,255);
	renderer.clear();

    AssetsLoader assets(renderer);

    Texture people(renderer);
    people.loadFromFile("Images/dot.bmp", true, {0, 255, 255});

    MapGraphic map("hola.json", assets, 25, 25);

    Screen background("Images/bg.png", renderer, config.getValue("window_width"), config.getValue("window_height"), map);
    background.moveToCenter();
    
    PlayerGraphic player(assets, 24, 0);        

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
        std::cout << "Time: " << elapsedTime << " µs" << std::endl;
        std::cout << "Microseconds per Frame: " << microsecondsPerFrame << std::endl;
        
        int waitTime = microsecondsPerFrame - elapsedTime;
        std::cout << "Waiting time 2: " << waitTime << " µs" << std::endl;

        if (waitTime > 0)
            usleep(waitTime);
        else
            std::cout << "NEGATIVE " << waitTime << " µs" << std::endl;
        
        std::cout << frame++ << std::endl;
    }
}