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

Client::Client(Window& window, std::string& race, std::string& type): 
                                window(window), 
                                renderer(window.getRenderer()), 
                                config(Configuration::getInstance()),
                                assets(AssetsLoader(renderer)), 
                                gui(GraphicalInterface(assets)), 
                                sender(Sender(intentions, commands, race, type)),
                                map(MapGraphic("mapFinal.json", assets)),
                                screen(Screen(map, renderer, config.getValue("window_width"), config.getValue("window_height"))),
                                musicPlayer(MusicPlayer(assets)),
                                entities(EntityContainer(assets, screen)),
                                effects(SFXGenerator(screen, assets)),
                                eventHandler(EventHandler(*this, intentions)),
                                continueExectuion(true){

    Configuration& config = Configuration::getInstance();

    int windowWidth = config.getValue("window_width");
    int windowHeight = config.getValue("window_height");
    mapViewport = {(int) (windowWidth / 80), (int) (windowHeight / 60), (int) (windowWidth / 1.45), (int) (windowHeight / 1.02)};
    renderer.setViewport(&mapViewport);

    screen.updateCamera();
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

void Client::addPlayer(int entityId, int x, int y, std::string& race){
    entities.addPlayer(entityId, x, y, race);
}

void Client::removeMob(int entityId){
    entities.removeMob(entityId);
}

void Client::addMapItem(int itemId, int x, int y){
    map.addItem(x, y, itemId);
}

void Client::idleEntity(int entityId, int x, int y){
    entities.idle(entityId, x, y);
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

void Client::equipWeapon(int entityId, int itemId){
    entities.equipWeapon(entityId, itemId);
}

void Client::equipArmor(int entityId, int itemId){
    entities.equipArmor(entityId, itemId);
}

void Client::equipShield(int entityId, int itemId){
    entities.equipShield(entityId, itemId);
}

void Client::equipHelmet(int entityId, int itemId){
    entities.equipHelmet(entityId, itemId);
}

void Client::removeItemMap(int x, int y){
    map.removeItem(x, y);
}

void Client::updateHealth(int health){
    gui.updateHealth(health);
}

void Client::updateLevel(int level){
    gui.updateLevel(level);
    effects.addLevelUpEffect();
}

void Client::updateExperience(int experience){
    gui.updateExperience(experience);
}

void Client::updateMana(int mana){
    gui.updateMana(mana);
}

void Client::updateGold(int gold){
    gui.updateGold(gold);
}

void Client::notifyAttack(int itemId, int x, int y, int duration){
    effects.addAttackEffect(itemId, x, y, duration);
}

std::pair<int, int> Client::getMapCoordinates(int x, int y){
    return screen.getMapCoordinates(x, y);
}

bool Client::isClickOnMapScreen(int x, int y){
    return (x > mapViewport.x) && (x < (mapViewport.x + mapViewport.w)) &&
            (y > mapViewport.y) && (y < mapViewport.y + mapViewport.h);
}

void Client::showProducts(std::vector<int>& products){
    eventHandler.openStore();
    std::cout << "Elija un producto para comprar:" << std::endl;
    for (size_t i = 0; i < products.size() / 2; i++){
        std::cout << i + 1 << ". Item " << products[2 * i] << " - $" << products[2 * i + 1] << std::endl;
    }
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
        renderer.setViewport(&mapViewport);

        screen.centerToPlayerPosition(entities);
        screen.render();
        entities.update(microsecondsPerFrame);
        renderer.resetViewport();
        effects.render(microsecondsPerFrame);
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
