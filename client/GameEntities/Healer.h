#ifndef HEALER_ENTITY_H
#define HEALER_ENTITY_H
#include <memory>
#include "GameEntity.h"
#include "MovableEntity.h"
#include "../State/State.h"
#include <vector>

class GameMap;

class Sender;

class Healer: public MovableEntity{
    private:

    public:
        Healer(Sender& game, GameMap& map, int entityId, int x, int y);
        //Healer(Healer&&);
        void notifyMovement(int direction, int x, int y);
        void notifyPlayerMovement(int x, int y);
        void moveInventoryItem(int from, int to);
        void attackEntity(MovableEntity& other);
        void kill(MovableEntity& killer);
        bool evadeAttack();
        void notifyHealthUpdate(int newHealth);
        void notifyExperienceUpdate(int experience);
        void notifyLevelUpdate(int level);
        void notifyManaUpdate(int mana);
        void notifyGoldUpdate(int gold);
        bool addItem(int itemId, int slot);
        int getDefense(int damage);
        void update(int timeElapsed) override;
        void interact(MovableEntity& other);
        void revive();
        void buyItem(MovableEntity& buyer, int itemIndex);
        ~Healer();
};

#endif 
