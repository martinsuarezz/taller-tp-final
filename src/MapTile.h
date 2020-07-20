#ifndef MAP_TILE_H
#define MAP_TILE_H

class MovableEntity;

// Clase que modela un tile del mapa del juego.

class MapTile{
    private:
        MovableEntity* entity;
        int item;
        bool solid;

    public:
        MapTile();

        // Setea el tile como sólido impidiendo que
        // hayan entidades en el mismo.
        void setSolid();

        // Remueve la entidad del tile recibido y la
        // ubica en este objeto.
        void transferEntity(MapTile& other);

        // Remueve la entidad del tile.
        void removeEntity();

        // Agrega una entidad al tile.
        void addEntity(MovableEntity* entity);

        // Chequea si hay una entidad.
        bool hasEntity();

        // Chequea si el tile es sólido.
        bool isSolid();

        // Obtiene la entidad que se encuentra en este tile.
        MovableEntity* getEntity();

        // Obtiene la id del item que se ubica en este tile.
        int getItemId();

        // Remueve el item del tile.
        void removeItem();

        // Agrega un item al tile.
        void addItem(int itemId);
};

#endif
