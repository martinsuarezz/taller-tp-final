#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H
#include <memory>
#include "GameEntity.h"
#include "MovableEntity.h"
#include "../State/State.h"

class GameMap;

class Sender;

class GameEntityContainer;

class Player: public MovableEntity{
    private:
        GameEntityContainer& entities;

    public:
        Player(Sender& game, GameMap& map, GameEntityContainer& entities, int entityId, int x, int y);
        //Player(Player&&);
        void notifyMovement(int direction, int x, int y);
        void notifyIdle();
        void notifyPlayerMovement(int x, int y);
        ~Player();
};

#endif 
