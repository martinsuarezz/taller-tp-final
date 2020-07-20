#ifndef EFFECT_H
#define EFFECT_H
#include "Animation/Animation.h"

class Sound;

class Texture;

// Clase que modela un efecto especial de animación
// a mostrar en la parte gráfica.

class Effect{
    private:
        Animation animation;
        int x;
        int y;
        bool finished;
        int duration;
        int time;

    public:
        // Recibe la animación, las coordenadas donde mostrarla y la duración.
        Effect(Animation&& animation, int x, int y, int duration);
        Effect(Effect&&);

        // Renderiza la animación, debe recibir las coordenadas de donde
        // comienza la pantalla para poder renderizarla relativa a la misma.
        void render(int timeElapsed, int xScreen, int yScreen);

        // Devuelve si la animación ya se completó.
        bool hasFinished();

};

#endif
