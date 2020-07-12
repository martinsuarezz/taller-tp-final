#ifndef MOVABLE_ENTITY_H
#define MOVABLE_ENTITY_H
#include <memory>
#include "GameEntity.h"
#include "../State/State.h"

class GameMap;

class Sender;

class MovableEntity: public GameEntity{
    protected:
        std::unique_ptr<State> state;
        std::unique_ptr<State> nextState;
        int entityId;
        int moveSpeed;
        int health;

    public:
        MovableEntity(Sender& game, GameMap& map, int entityId, int x, int y, int moveSpeed);
        //MovableEntity(MovableEntity&&);
        void move(int direction);
        void moveUp();
        void moveRight();
        void moveDown();
        void moveLeft();
        void stop();
        virtual void notifyMovement(int direction, int x, int y) = 0;
        void notifyIdle();
        virtual void update(int time);
        void changeState();
        bool canMove(int x, int y);
        void updatePosition(int x, int y);
        void getAttacked(int damage, bool critical = false);
        int getId();
        bool isInRange(MovableEntity& other, int range);
        virtual int getDefense(int damage) = 0;
        virtual void attackEntity(MovableEntity& other) = 0;
        virtual void notifyPlayerMovement(int x, int y) = 0;
        virtual void moveInventoryItem(int from, int to) = 0;
        virtual void addItem(int itemId, int slot) = 0;
        virtual ~MovableEntity();
};

#endif 
