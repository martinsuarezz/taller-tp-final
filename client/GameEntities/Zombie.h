#ifndef ZOMBIE_ENTITY_H
#define ZOMBIE_ENTITY_H
#include <memory>
#include "GameEntity.h"
#include "MovableEntity.h"
#include "../State/State.h"
#include "ZombieAI.h"

class GameMap;

class Sender;

class Zombie: public MovableEntity{
    private:
        int visionRange;
        ZombieAI zombieAI;

    public:
        Zombie(Sender& game, GameMap& map, int entityId, int x, int y);
        //Zombie(Zombie&&);
        void notifyMovement(int direction, int x, int y);
        void notifyIdle();
        void notifyPlayerMovement(int x, int y);
        bool isInVisionRange(int x, int y);
        bool isInRange(int x, int y, int range);
        void moveTowards(int x, int y);
        void moveInventoryItem(int from, int to);
        void attackEntity(MovableEntity& other);
        void attackPlayer();
        void kill();
        bool evadeAttack();
        void notifyHealthUpdate(int newHealth);
        void notifyExperienceUpdate(int experience);
        void notifyLevelUpdate(int level);
        void notifyManaUpdate(int mana);
        void addItem(int itemId, int slot);
        int getDefense(int damage);
        bool hasManaAvailable(int neededMana) override;
        void update(int timeElapsed) override;
        ~Zombie();
};

#endif 
