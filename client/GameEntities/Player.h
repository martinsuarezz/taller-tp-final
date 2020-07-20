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
        std::string race;
        std::string type;
        int strength;
        int agility;

    public:
        Player(Sender& game, GameMap& map, GameEntityContainer& entities, 
            int entityId, std::string race, std::string type, int x, int y, int duration);
        void notifyMovement(int direction, int x, int y);
        void notifyIdle();
        void notifyPlayerMovement(int x, int y);
        void moveInventoryItem(int from, int to);
        bool addItem(int itemId, int slot);
        void attackEntity(MovableEntity& entity);
        void notifyHealthUpdate(int newHealth);
        void notifyExperienceUpdate(int experience);
        void notifyLevelUpdate(int level);
        void notifyManaUpdate(int mana);
        void notifyGoldUpdate(int gold);
        void update(int timeElapsed);
        bool evadeAttack();
        int removeItem(int slot);
        void kill(MovableEntity& killer);
        int getDefense(int damage);
        void interact(MovableEntity& other);
        void revive();
        void buyItem(MovableEntity& buyer, int itemIndex);
        ~Player();
};

#endif 
