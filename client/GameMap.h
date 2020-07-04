#ifndef GAME_MAP_H
#define GAME_MAP_H
#include <tuple>

class GameEntity;

class GameMap{
    private:
        GameEntity* map[20][20];
        int width;
        int height;
        int entitiesAmmount;
        bool isInbound(int x, int y) const;
        int getWidth() const;
        int getHeight() const;

    public:
        GameMap();
        bool move(int fromX, int fromY, int toX, int toY);
        void remove(int fromX, int fromY);
        bool isEmpty(int x, int y) const;
        void addEntity(GameEntity* entity, int x, int y);
        bool canMove(int x, int y) const;
        std::pair<int, int> getEmptyPosition();

};

#endif
