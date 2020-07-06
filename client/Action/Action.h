#ifndef ACTION_H
#define ACTION_H
#include <vector>
#include "../SoundPlayer.h"
#include "../Animation/Animation.h"

class Entity;

class Action{
    protected:
        std::vector<Animation> animations;
        Entity& entity;
        std::vector<SoundPlayer> sounds;
        void render();

    public:
        Action(Entity& entity);
        virtual void update() = 0;
        virtual void walk(std::string direction) = 0;
        virtual void idle() = 0;
};

#endif
