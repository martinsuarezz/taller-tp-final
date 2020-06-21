#ifndef WALKING_ACTION_H
#define WALKING_ACTION_H
#include <vector>
#include "Animation.h"
#include "Action.h"
#include <map>

class Entity;

class AssetsLoader;

class WalkingAction: public Action{
    private:
        AssetsLoader& assets;
        std::string direction;
        int distance;
        int remainingFrames;

    public:
        WalkingAction(Entity& player, AssetsLoader& assets, std::string direction, int distance);
        void update();
        void walk(std::string direction, int distance);
        void updatePosition();
};

#endif
