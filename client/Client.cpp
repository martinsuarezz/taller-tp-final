#include "Client.h"
#include "Renderer.h"
#include "Sound.h"
#include "Screen.h"
#include "Window.h"
#include "MapGraphic.h"
#include "Texture.h"
#include "AssetsLoader.h"
#include "EntityFactory.h"
#include "Configuration.h"
#include "Clock.h"
#include "Entity.h"
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

    int windowWidth = config.getValue("window_width");
    int windowHeight = config.getValue("window_height");
    SDL_Rect viewport = {(int) (windowWidth / 80), (int) (windowHeight / 60), (int) (windowWidth / 1.45), (int) (windowHeight / 1.02)};
    renderer.setViewport(&viewport);

    AssetsLoader assets(renderer);

    MapGraphic map("hola.json", assets, 25, 25);

    Screen mapScreen(map, renderer, config.getValue("window_width"), config.getValue("window_height"));

    Texture& gui = assets.getTexture("interface");
    gui.setHeight(windowHeight);
    gui.setWidth(windowWidth);

    EntityFactory factory(assets, mapScreen);
    Entity player(std::move(factory.getPlayer(20, 14)));
    
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
        renderer.setViewport(&viewport);
        mapScreen.centerToPosition(player.getX(), player.getY());
        mapScreen.render();
        player.update();
        renderer.resetViewport();
        gui.render(0, 0);

        renderer.renderPresent();        

        clock.stop();
        int elapsedTime = clock.getDuration();        
        int waitTime = microsecondsPerFrame - elapsedTime;

        if (waitTime > 0)
            usleep(waitTime);
    }
}
