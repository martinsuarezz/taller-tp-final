#ifndef ZOMBIE_ATTACKING_STATE_H
#define ZOMBIE_ATTACKING_STATE_H
#include "State.h"

class MovableEntity;

class GameItem;

// Clase que modela el estado de ataque de un zombie.

class ZombieAttackingState: public State{
    private:
        MovableEntity& objective;
        int strength;
        int duration;

    public:
        ZombieAttackingState(MovableEntity& entity, MovableEntity& objective, int strength, int duration);
        
        // Actualiza el estado notificando el paso del tiempo.
        void update(int time);

        // Devuelve si es válido atacar a la entidad objetivo.
        bool isValid();

        // Activa el estado realizando el ataque.
        void activate();

};

#endif
