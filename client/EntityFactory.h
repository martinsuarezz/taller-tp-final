#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H
#include "Entity.h"

class AssetsLoader;

class Screen;

class EntityFactory{
    private:
        AssetsLoader& assets;
        Screen& screen;

    public:
        EntityFactory(AssetsLoader& assets, Screen& screen);
        Entity getPlayer(int x, int y);
        Entity getZombie(int x, int y);

};

#endif
