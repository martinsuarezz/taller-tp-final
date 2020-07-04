#ifndef ENTITY_CONTAINER_H
#define ENTITY_CONTAINER_H
#include "EntityFactory.h"
#include <map>
#include "Entity.h"

class AssetsLoader;

class Screen;

class EntityContainer{
    private:
        EntityFactory factory;
        std::map<int, Entity> entities;
        int playerId;

    public:
        EntityContainer(AssetsLoader& assets, Screen& screen);
        void move(int entityId, int direction, int x, int y);
        void idle(int entityId, int x, int y);
        void addMob(int entityId, int x, int y, int type);
        void addPlayer(int entityId, int x, int y);
        void update();
        Entity& getPlayer();


};

#endif
