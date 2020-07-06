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
#include "Command/Command.h"
#include "EventHandler.h"
#include "MusicPlayer.h"
#include "Constants.h"
#include "EntityContainer.h"
#include <iostream>
#include <unistd.h>

Client::Client(Window& window): window(window), 
                                renderer(window.getRenderer()), 
                                config(Configuration::getInstance()),
                                assets(AssetsLoader(renderer)), 
                                gui(GraphicalInterface(assets)), 
                                sender(Sender(intentions, commands)),
                                map(MapGraphic("mapFinal.json", assets)),
                                screen(Screen(map, renderer, config.getValue("window_width"), config.getValue("window_height"))),
                                musicPlayer(MusicPlayer(assets)),
                                entities(EntityContainer(assets, screen)),
                                continueExectuion(true){

}

void Client::addItem(int itemId, int position){
    gui.addItemInventory(itemId, position);
}

void Client::removeItem(int position){
    gui.removeItemInventory(position);
}

void Client::moveItem(int from, int to){
    gui.moveItemInventory(from, to);
}

void Client::moveEntity(int entityId, int direction, int x, int y){
    entities.move(entityId, direction, x, y);
}

void Client::addMob(int entityId, int x, int y, int type){
    entities.addMob(entityId, x, y, type);
}

void Client::addPlayer(int entityId, int x, int y){
    entities.addPlayer(entityId, x, y);
}

void Client::removeMob(int entityId){
    entities.removeMob(entityId);
}

void Client::idleEntity(int entityId, int x, int y){
    entities.idle(entityId, x, y);
    //entities.at(entityId).idle(x * 100, y * 100);
}

void Client::nextSong(){
    musicPlayer.nextTrack();
}

void Client::previousSong(){
    musicPlayer.previousTrack();
}

void Client::stopPlaySong(){
    musicPlayer.switchPlayStop();
}

void Client::stopExecution(){
    continueExectuion = false;
}

GraphicalInterface& Client::getGui(){
    return gui;
}

void Client::run(){
    Configuration& config = Configuration::getInstance();
    sender.start();

    int microsecondsPerFrame = 1000000 / config.getValue("fps");

    renderer.setDrawColor(200, 255, 255, 255);
	renderer.clear();

    int windowWidth = config.getValue("window_width");
    int windowHeight = config.getValue("window_height");
    SDL_Rect viewport = {(int) (windowWidth / 80), (int) (windowHeight / 60), (int) (windowWidth / 1.45), (int) (windowHeight / 1.02)};
    renderer.setViewport(&viewport);

    screen.updateCamera();

    /*
    MapGraphic map("hola.json", assets, 25, 25);

    Screen mapScreen(map, renderer, config.getValue("window_width"), config.getValue("window_height"));
    
    EntityFactory factory(assets, mapScreen);
    entities.emplace(0, std::move(factory.getPlayer(20, 14)));
    entities.emplace(1, std::move(factory.getZombie(404, 14)));
    Entity& player = entities.at(0);
    */

    addItem(1, 0);
    addItem(1, 1);
    addItem(1, 14);
    moveItem(0, 15);

    EventHandler eventHandler(*this, intentions);

    Clock clock;

    while (continueExectuion){
        clock.start();

        eventHandler.handle(20, 50);
        
        while (!commands.isEmpty()){
            std::unique_ptr<Command> command;
            command.reset(commands.pop());
            command->execute(*this);
        }

        musicPlayer.continuePlaying();
        renderer.clear();
        renderer.setViewport(&viewport);

        screen.centerToPlayerPosition(entities);
        screen.render();
        entities.update(16667);
        renderer.resetViewport();
        gui.render();

        renderer.renderPresent();   

        clock.stop();
        int elapsedTime = clock.getDuration();        
        int waitTime = microsecondsPerFrame - elapsedTime;

        if (waitTime > 0)
            usleep(waitTime);
        else
            std::cout << "Warning: se tardo mucho tiempo: " << elapsedTime << " μs" << std::endl;
        
    }
    sender.join();
}
