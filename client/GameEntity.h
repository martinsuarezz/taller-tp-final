#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H
#include <memory>
#include "State/State.h"

class GameMap;

class Sender;

class GameEntity{
    private:
        Sender& game;
        GameMap& map;
        std::unique_ptr<State> state;
        int entityId;
        int x;
        int y;

    public:
        GameEntity(Sender& game, GameMap& map, int entityId);
        void move(int direction);
        void moveUp();
        void moveRight();
        void moveDown();
        void moveLeft();
        void notifyMovement(int direction, int x, int y);
        void update(int time);
};

#endif
