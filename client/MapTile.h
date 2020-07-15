#ifndef MAP_TILE_H
#define MAP_TILE_H

class MovableEntity;

class MapTile{
    private:
        MovableEntity* entity;
        int item;
        bool solid;

    public:
        MapTile();
        void setSolid();
        void transferEntity(MapTile& other);
        void removeEntity();
        void addEntity(MovableEntity* entity);
        bool hasEntity();
        bool isSolid();
        MovableEntity* getEntity();
        int getItemId();
        void removeItem();
        void addItem(int itemId);
};

#endif
