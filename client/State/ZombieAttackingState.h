#ifndef ZOMBIE_ATTACKING_STATE_H
#define ZOMBIE_ATTACKING_STATE_H
#include "State.h"

class MovableEntity;

class GameItem;

class ZombieAttackingState: public State{
    private:
        MovableEntity& objective;
        int strength;
        int duration;

    public:
        ZombieAttackingState(MovableEntity& entity, MovableEntity& objective, int strength, int duration);
        
        // Actualiza el estado notificando el paso del tiempo.
        void update(int time);

        bool isValid();

        void activate();

};

#endif
