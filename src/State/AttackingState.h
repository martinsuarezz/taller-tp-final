#ifndef ATTACKING_STATE_H
#define ATTACKING_STATE_H
#include "State.h"

class MovableEntity;

class GameItem;

// Clase que modela el estado de estar atacando.

class AttackingState: public State{
    private:
        MovableEntity& objective;
        GameItem& weapon;
        int strength;
        int duration;

    public:
        AttackingState(MovableEntity& entity, MovableEntity& objective, GameItem& weapon, int strength);
        
        // Actualiza el estado notificando el paso del tiempo.
        void update(int time);

        // Chequea si es válido el ataque.
        bool isValid();

        // Activa el estado.
        void activate();

};

#endif
