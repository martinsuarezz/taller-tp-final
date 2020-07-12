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
#include <map>

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
        SDL_Rect mapViewport;
        bool continueExectuion;

    public:
        Client(Window& window);
        void run();
        void updateEntities();
        void moveEntity(int entityId, int direction, int x, int y);
        void idleEntity(int entityId, int x, int y);
        void addItem(int itemId, int position);
        void removeItem(int position);
        void moveItem(int from, int to);
        void equipWeapon(int entityId, int itemId);
        void equipArmor(int entityId, int itemId);
        void addMob(int entityId, int x, int y, int type);
        void removeMob(int entityId);
        void addPlayer(int entityId, int x, int y);
        void stopExecution();
        void nextSong();
        void stopPlaySong();
        void previousSong();
        std::pair<int, int> getMapCoordinates(int x, int y);
        bool isClickOnMapScreen(int x, int y);
        GraphicalInterface& getGui();

};

#endif
