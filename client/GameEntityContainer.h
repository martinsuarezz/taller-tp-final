#ifndef GAME_ENTITY_CONTAINER 
#define GAME_ENTITY_CONTAINER
#include <map>
#include "GameEntities/MovableEntity.h"
#include "GameEntities/GameEntityFactory.h"
#include "IdStack.h"

class Sender;

class GameMap;

class GameEntityContainer{
    private:
        Sender& game;
        GameMap& map;
        std::map<int, MovableEntity*> mobs;
        IdStack ids;
        size_t maxMobs;
        GameEntityFactory factory;
        int mobSpawnProb;

    public:
        GameEntityContainer(Sender& game, GameMap& map);
        void addPlayer(int x, int y);
        void addMob(int x, int y, int type);
        void removeMob(int id);
        void update(int timeElapsed);
        void move(int id, int direction);
        void stop(int id);
        void notifyPlayerMovement(int x, int y);
        void spawnHostileMob();
        void addItem(int entityId, int itemId, int slot);
        void attack(int from, int to);
        MovableEntity* getMob(int id);
        void moveInventoryItem(int id, int from, int to);
        ~GameEntityContainer();
};

#endif
