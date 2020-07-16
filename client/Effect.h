#ifndef EFFECT_H
#define EFFECT_H
#include "Animation/Animation.h"

class Sound;

class Texture;

class Effect{
    private:
        Animation animation;
        int x;
        int y;
        bool finished;
        int duration;
        int time;

    public:
        Effect(Animation&& animation, int x, int y, int duration);
        Effect(Effect&&);
        void render(int timeElapsed, int xScreen, int yScreen);
        bool hasFinished();

};

#endif
