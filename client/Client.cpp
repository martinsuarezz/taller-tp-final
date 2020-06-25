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
#include "GraphicalInterface.h"
#include "Clock.h"
#include "Entity.h"
#include "CommandsQueue.h"
#include "Command.h"
#include "EventHandler.h"
#include <iostream>
#include <unistd.h>

#define WALK_DISTANCE 64

Client::Client(Window& window): window(window), 
                                renderer(window.getRenderer()), 
                                assets(AssetsLoader(renderer)), 
                                gui(GraphicalInterface(assets)), 
                                communicator(Communicator(commands)),
                                continueExectuion(true){

}

void Client::addItem(int itemId, int position){
    gui.addItem(itemId, position);
}

void Client::removeItem(int position){
    gui.removeItem(position);
}

void Client::moveItem(int from, int to){
    gui.moveItem(from, to);
}

void Client::moveEntity(int entityId, int direction, int x, int y){
    switch(direction){
        case 0:
            entities.at(entityId).moveUp(x, y);
            break;
        case 1:
            entities.at(entityId).moveRight(x, y);
            break;
        case 2:
            entities.at(entityId).moveDown(x, y);
            break;
        case 3:
            entities.at(entityId).moveLeft(x, y);
            break;
    }
}

void Client::updateEntities(){
    std::map<int, Entity>::iterator it;
    for (it = entities.begin(); it != entities.end(); it++){
        it->second.update();
    }
}

void Client::stopExecution(){
    continueExectuion = false;
}

GraphicalInterface& Client::getGui(){
    return gui;
}

void Client::run(){
    Configuration& config = Configuration::getInstance();
    //communicator.start();

    int microsecondsPerFrame = 1000000 / config.getValue("fps");

    renderer.setDrawColor(200, 255, 255, 255);
	renderer.clear();

    int windowWidth = config.getValue("window_width");
    int windowHeight = config.getValue("window_height");
    SDL_Rect viewport = {(int) (windowWidth / 80), (int) (windowHeight / 60), (int) (windowWidth / 1.45), (int) (windowHeight / 1.02)};
    renderer.setViewport(&viewport);

    MapGraphic map("hola.json", assets, 25, 25);

    Screen mapScreen(map, renderer, config.getValue("window_width"), config.getValue("window_height"));

    EntityFactory factory(assets, mapScreen);
    entities.emplace(std::make_pair(1, std::move(factory.getPlayer(20, 14))));
    entities.emplace(std::make_pair(2, std::move(factory.getZombie(404, 14))));
    Entity& player = entities.at(1);

    addItem(1, 0);
    addItem(1, 1);
    addItem(1, 2);
    addItem(1, 3);
    addItem(1, 11);
    addItem(1, 6);
    addItem(1, 12);
    addItem(1, 13);
    addItem(1, 14);
    moveItem(0, 15);

    EventHandler eventHandler(*this);

    Clock clock;

    while (continueExectuion){
        clock.start();

        eventHandler.handle(20, 50);
        /*
        while (!commands.isEmpty()){
            std::unique_ptr<Command> command;
            command.reset(commands.pop());
            command->execute(*this);
        }
        */
        renderer.clear();
        renderer.setViewport(&viewport);
        mapScreen.centerToPosition(player.getX(), player.getY());
        mapScreen.render();
        updateEntities();
        renderer.resetViewport();
        gui.render();

        renderer.renderPresent();   

        clock.stop();
        int elapsedTime = clock.getDuration();        
        int waitTime = microsecondsPerFrame - elapsedTime;

        if (waitTime > 0)
            usleep(waitTime);
        else
            std::cout << "Warning: se tardo mucho tiempo" << std::endl;
        
    }
    //communicator.join();
}
