#ifndef ZOMBIE_ENTITY_H
#define ZOMBIE_ENTITY_H
#include <memory>
#include "GameEntity.h"
#include "MovableEntity.h"
#include "../State/State.h"

class GameMap;

class Sender;

class Zombie: public MovableEntity{
    private:
        int visionRange;
        bool isInRange(int x, int y, int range);

    public:
        Zombie(Sender& game, GameMap& map, int entityId, int x, int y);
        //Zombie(Zombie&&);
        void notifyMovement(int direction, int x, int y);
        void notifyIdle();
        void notifyPlayerMovement(int x, int y);
        bool isInVisionRange(int x, int y);
        void moveTowards(int x, int y);
        void moveInventoryItem(int from, int to);
        void attackEntity(MovableEntity& other);
        void addItem(int itemId, int slot);
        ~Zombie();
};

#endif 
