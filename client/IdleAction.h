#ifndef IDLE_ACTION_H
#define IDLE_ACTION_H
#include <vector>
#include "Animation.h"
#include "Action.h"

class PlayerGraphic;

class AssetsLoader;

class IdleAction: public Action{
    private:
        AssetsLoader& assets;

    public:
        IdleAction(PlayerGraphic& player, AssetsLoader& assets);
        void update();
        void walk(std::string direction, int distance);
};

#endif
