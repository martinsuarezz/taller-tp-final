#ifndef MOVABLE_ENTITY_H
#define MOVABLE_ENTITY_H
#include <memory>
#include "GameEntity.h"
#include "../State/State.h"

class GameMap;

class Sender;

class MovableEntity: public GameEntity{
    private:
        std::unique_ptr<State> state;
        std::unique_ptr<State> nextState;
        int entityId;

    public:
        MovableEntity(Sender& game, GameMap& map, int entityId, int x, int y);
        MovableEntity(MovableEntity&&);
        void move(int direction);
        void moveUp();
        void moveRight();
        void moveDown();
        void moveLeft();
        void stop();
        void notifyMovement(int direction, int x, int y);
        void notifyIdle();
        void update(int time);
        void changeState();
        bool canMove(int x, int y);
        void updatePosition(int x, int y);
};

#endif 
