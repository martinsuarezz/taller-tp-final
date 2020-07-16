#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H
#include "Entity.h"

class AssetsLoader;

class Screen;

// Clase que modela una factory de entidades para
// abstraerse de la creación de las mismas.

class EntityFactory{
    private:
        AssetsLoader& assets;
        Screen& screen;

    public:
        EntityFactory(AssetsLoader& assets, Screen& screen);

        // Devuelve una entidad jugador ubicado en las coordenadas dadas.
        Entity getPlayer(int x, int y, std::string& race);

        // Devuelve una entidad zombie ubicado en las coordenadas dadas.
        Entity getZombie(int x, int y);

};

#endif
