#ifndef ACTION_H
#define ACTION_H
#include <vector>
#include "../SoundPlayer.h"
#include "../Animation/Animation.h"

class Entity;

// Clase que modela una acción de una entidad.
// Representa el estado en el que se encuentra una entidad de
// la parte gráfica.

class Action{
    protected:
        std::vector<Animation> animations;
        Entity& entity;
        std::vector<SoundPlayer> sounds;

        // Renderiza las texturas de la entidad.
        void render();

    public:
        Action(Entity& entity);

        virtual void update() = 0;
        virtual void walk(std::string direction) = 0;
        virtual void idle() = 0;
};

#endif
