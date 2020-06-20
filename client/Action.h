#ifndef ACTION_H
#define ACTION_H
#include <vector>
#include "Animation.h"

class PlayerGraphic;

class Action{
    protected:
        std::vector<Animation> animations;
        PlayerGraphic& player;
        void render();

    public:
        Action(PlayerGraphic& player);
        virtual void update() = 0;
        virtual void walk(std::string direction, int distance) = 0;
};

#endif
