#ifndef SFX_GENERATOR_H
#define SFX_GENERATOR_H
#include <list>
#include "Effect.h"

class Screen;

class AssetsLoader;

// Clase que se encarga de manejar las animaciones
// y sonidos del juego. 

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

        // Notifica el paso del tiempo a las animaciones y renderiza.
        void render(int timeElapsed);

        // Agrega distintos efectos a mostrar, reproduce los sonidos.
        void addAttackEffect(int weapon, int x, int y, int duration);
        void removeEffect(int effectNumber);
        void addLevelUpEffect();
        void addMerchantEffect();
        void addPlayerDeathEffect();
        void addPlayerReviveEffect();

};

#endif
