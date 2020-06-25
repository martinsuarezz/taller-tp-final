#ifndef CLIENT_H
#define CLIENT_H
#include "Communicator.h"
#include "GraphicalInterface.h"
#include "AssetsLoader.h"
#include "Entity.h"
#include "CommandsQueue.h"
#include <map>

class Window;

class Client{
    private:
        Window& window;
        Renderer& renderer;
        AssetsLoader assets;
        GraphicalInterface gui;
        CommandsQueue commands;
        Communicator communicator;
        std::map<int, Entity> entities;
        bool continueExectuion;

    public:
        Client(Window& window);
        void run();
        void updateEntities();
        void moveEntity(int entityId, int direction, int x, int y);
        void addItem(int itemId, int position);
        void removeItem(int position);
        void moveItem(int from, int to);
        void stopExecution();
        GraphicalInterface& getGui();

};

#endif
