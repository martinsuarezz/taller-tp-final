#ifndef GAME_ENTITY_CONTAINER 
#define GAME_ENTITY_CONTAINER
#include <map>
#include "GameEntities/MovableEntity.h"
#include "GameEntities/GameEntityFactory.h"
#include "IdStack.h"

class Sender;

class GameMap;

// Clase que se encarga de almacenar las entidades
// del juego desde la parte de la lógica de juego.

class GameEntityContainer{
    private:
        Sender& game;
        GameMap& map;
        std::map<int, MovableEntity*> mobs;
        IdStack ids;
        size_t maxMobs;
        GameEntityFactory factory;
        int mobSpawnProb;

        void spawnHostileMob();

    public:
        GameEntityContainer(Sender& game, GameMap& map);

        // Agrega una entidad al juego.
        void addPlayer(int x, int y, std::string& race, std::string& type);
        void addMob(int x, int y, int type, int level = 1);

        // Remueve una entidad del juego.
        void removeMob(int id);

        // Actualiza a las entidades según el paso del tiempo.
        void update(int timeElapsed);

        // Ordena a cierta entidad que debe moverse.
        void move(int id, int direction);

        // Ordena a cierta entidad que debe detenerse.
        void stop(int id);

        // Le notifica a las distintas entidades que un jugador
        // se está moviendo, para que puedan actuar en consecuencia.
        void notifyPlayerMovement(int x, int y);

        // Agrega un item a una entidad.
        void addItem(int entityId, int itemId, int slot);

        // Le notifica a una entidad que debe atacar a otra.
        void attack(int from, int to);

        // Obtiene una entidad.
        MovableEntity* getMob(int id);

        // Mueve un item del inventario de una 
        // entidad de un lugar a otro.
        void moveInventoryItem(int id, int from, int to);
        
        ~GameEntityContainer();
};

#endif
