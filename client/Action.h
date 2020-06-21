#ifndef ACTION_H
#define ACTION_H
#include <vector>
#include "Animation.h"

class Entity;

class Action{
    protected:
        std::vector<Animation> animations;
        Entity& entity;
        void render();

    public:
        Action(Entity& entity);
        virtual void update() = 0;
        virtual void walk(std::string direction, int distance) = 0;
};

#endif
