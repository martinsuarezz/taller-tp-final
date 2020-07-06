#ifndef GAME_ENTITY_CONTAINER 
#define GAME_ENTITY_CONTAINER
#include <map>
#include "GameEntities/MovableEntity.h"
#include "IdStack.h"

class Sender;

class GameMap;

class GameEntityContainer{
    private:
        Sender& game;
        GameMap& map;
        std::map<int, MovableEntity*> mobs;
        IdStack ids;
        MovableEntity* getMob(int id);
        size_t maxMobs;

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

};

#endif