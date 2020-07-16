#ifndef CLIENT_H
#define CLIENT_H
#include "Sender.h"
#include "GraphicalInterface.h"
#include "AssetsLoader.h"
#include "Entity.h"
#include "CommandsQueue.h"
#include "IntentionsQueue.h"
#include "MusicPlayer.h"
#include "EntityContainer.h"
#include "MapGraphic.h"
#include "Screen.h"
#include "MapGraphic.h"
#include "SFXGenerator.h"
#include <map>
#include <string>

class Window;

class Configuration;

class Client{
    private:
        Window& window;
        Renderer& renderer;
        Configuration& config;
        AssetsLoader assets;
        GraphicalInterface gui;
        CommandsQueue commands;
        IntentionsQueue intentions;
        Sender sender;
        MapGraphic map;
        Screen screen;
        MusicPlayer musicPlayer;
        EntityContainer entities;
        SFXGenerator effects;
        SDL_Rect mapViewport;
        bool continueExectuion;

    public:
        Client(Window& window, std::string& race, std::string& type);
        void run();
        void updateEntities();
        void moveEntity(int entityId, int direction, int x, int y);
        void idleEntity(int entityId, int x, int y);
        void addItem(int itemId, int position);
        void addMapItem(int itemId, int x, int y);
        void removeItem(int position);
        void moveItem(int from, int to);
        void equipWeapon(int entityId, int itemId);
        void equipArmor(int entityId, int itemId);
        void equipShield(int entityId, int itemId);
        void equipHelmet(int entityId, int itemId);
        void addMob(int entityId, int x, int y, int type);
        void removeMob(int entityId);
        void addPlayer(int entityId, int x, int y, std::string& race);
        void removeItemMap(int x, int y);
        void updateHealth(int health);
        void updateLevel(int level);
        void updateExperience(int experience);
        void updateMana(int mana);
        void notifyAttack(int itemId, int x, int y, int duration);
        void stopExecution();
        void nextSong();
        void stopPlaySong();
        void previousSong();
        std::pair<int, int> getMapCoordinates(int x, int y);
        bool isClickOnMapScreen(int x, int y);
        GraphicalInterface& getGui();

};

#endif
