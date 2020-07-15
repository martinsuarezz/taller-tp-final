#ifndef GAME_MAP_H
#define GAME_MAP_H
#include <tuple>
#include <vector>
#include <string>
#include "MapTile.h"

class Sender;

class GameEntity;

class GameMap{
    private:
        Sender& game;
        std::vector<MapTile> map;
        int width;
        int height;
        int entitiesAmmount;
        bool isInbound(int x, int y) const;
        int getWidth() const;
        int getHeight() const;
        void setSolid(int tile);
        MapTile& getTile(int x, int y);

    public:
        GameMap(Sender& game, std::string mapFile);
        bool moveEntity(int fromX, int fromY, int toX, int toY);
        void remove(int fromX, int fromY);
        bool isMobPlacable(int x, int y);
        void addEntity(MovableEntity* entity, int x, int y);
        bool canMove(int x, int y);

        void addItem(int itemId, int x, int y);

        int getItemId(int x, int y);
        void removeItem(int x, int y);
        
        std::pair<int, int> getEmptyPosition();
        int getEntityId(int x, int y);
};

#endif
