#ifndef SFX_GENERATOR_H
#define SFX_GENERATOR_H
#include <list>
#include "Effect.h"

class Screen;

class AssetsLoader;

class SFXGenerator{
    private:
        Screen& screen;
        AssetsLoader& assets;
        std::list<Effect> effects;
        int time;
        void addMeleeEffect(int weapon, int duration);
        void addStaffEffect(int weapon, int x, int y, int duration);
        void addBowEffect(int weapon, int duration);

    public:
        SFXGenerator(Screen& screen, AssetsLoader& assets);
        void render(int timeElapsed);
        void addAttackEffect(int weapon, int x, int y, int duration);
        void removeEffect(int effectNumber);
        void addLevelUpEffect();

};

#endif
