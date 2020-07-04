#ifndef IDLE_ACTION_H
#define IDLE_ACTION_H
#include <vector>
#include <map>
#include <string>
#include "../Animation/Animation.h"
#include "Action.h"

class Entity;

class AssetsLoader;

class IdleAction: public Action{
    private:
        AssetsLoader& assets;

    public:
        IdleAction(Entity& player, AssetsLoader& assets);
        void update();
        void walk(std::string direction);
        void idle();
};

#endif
