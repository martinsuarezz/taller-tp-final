#ifndef GAME_MAP_H
#define GAME_MAP_H

class GameEntity;

class GameMap{
    private:
        GameEntity* map[20][20];

    public:
        bool move(int fromX, int fromY, int toX, int toY);
        void remove(int fromX, int fromY);
        bool isEmpty(int x, int y) const;
        void addEntity(GameEntity* entity, int x, int y);

};

#endif
