#ifndef GAME_MAP_H
#define GAME_MAP_H
#include <vector>
#include <string>
#include "MapTile.h"

class Sender;

class GameEntity;

// Clase que modela el mapa desde la parte
// lógica del juego.

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
        MovableEntity* getEntity(int x, int y);
        MapTile& getTile(int x, int y);

    public:
        GameMap(Sender& game, std::string mapFile);

        // Mueve una entidad de una posición a otra.
        bool moveEntity(int fromX, int fromY, int toX, int toY);

        // Remueve la entidad ubicada en la posición recibida.
        void remove(int fromX, int fromY);

        // Chequea si las coordenadas recibidas son aptas para
        // ubicar una entidad.
        bool isMobPlacable(int x, int y);

        // Agrega la entidad a la ubicación recibida.
        void addEntity(MovableEntity* entity, int x, int y);

        // Obtiene una entidad con la que se puede interaccionar
        // dentro del rango centrado en las coordenadas dadas.
        MovableEntity& getInteractableEntity(int x, int y, int range);

        // Agrega un item al mapa en las coordenadas dadas.
        void addItem(int itemId, int x, int y);

        // Obtiene la id del item en las coordenadas dadas.
        int getItemId(int x, int y);

        // Remueve un item en las coordenadas dadas.
        void removeItem(int x, int y);
        
        // Obtiene una posicón aleatoria del mapa que esté vacía.
        std::pair<int, int> getEmptyPosition();

        // Obtiene la id de la entidad ubicada en las coordenadas dadas.
        int getEntityId(int x, int y);
};

#endif
