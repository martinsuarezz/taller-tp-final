#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H
#include <memory>
#include "GameEntity.h"
#include "../GameInventory.h"
#include "MovableEntity.h"
#include "../State/State.h"

class GameMap;

class Sender;

class GameEntityContainer;

class Player: public MovableEntity{
    private:
        GameEntityContainer& entities;
        GameInventory inventory;
        int strength;

    public:
        Player(Sender& game, GameMap& map, GameEntityContainer& entities, int entityId, int x, int y);
        void notifyMovement(int direction, int x, int y);
        void notifyIdle();
        void notifyPlayerMovement(int x, int y);
        void moveInventoryItem(int from, int to);
        void addItem(int itemId, int slot);
        void attackEntity(MovableEntity& entity);
        int getDefense(int damage);
        ~Player();
};

#endif 
