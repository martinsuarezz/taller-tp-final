#ifndef ENTITY_CONTAINER_H
#define ENTITY_CONTAINER_H
#include "EntityFactory.h"
#include "Entity.h"
#include <map>

class AssetsLoader;

class Screen;

// Clase que se encarga de contener y organizar
// las entidades de la parte gráfica del modelo.

class EntityContainer{
    private:
        EntityFactory factory;
        std::map<int, Entity> entities;
        int playerId;

    public:
        EntityContainer(AssetsLoader& assets, Screen& screen);

        // Mueve la determinada entidad con la dirección y 
        // coordenadas indicadas.
        void move(int entityId, int direction, int x, int y);

        // Avisa a la entidad indicada que está idle.
        void idle(int entityId, int x, int y);

        // Agrega un monstruo.
        void addMob(int entityId, int x, int y, int type);

        // Agrega un jugador.
        void addPlayer(int entityId, int x, int y);

        // Remueve un monstruo o jugador.
        void removeMob(int entityId);

        void equipWeapon(int entityId, int itemId);

        // Actualiza a las entidades indicando el paso del tiempo.
        void update(int timeElapsed);

        // Obtiene la entidad correspondiente al jugador.
        Entity& getPlayer();

        //~EntityContainer();
};

#endif
