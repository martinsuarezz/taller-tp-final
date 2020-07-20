#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H
#include <memory>
#include "../State/State.h"

class GameMap;

class Sender;

// Clase que modela una entidad del juego.

class GameEntity{
    protected:
        Sender& game;
        GameMap& map;
        int x;
        int y;

    public:
        GameEntity(Sender& game, GameMap& map, int x, int y);
        void updatePosition(int x, int y);
        int getX();
        int getY();
};

#endif
