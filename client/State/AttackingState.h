#ifndef ATTACKING_STATE_H
#define ATTACKING_STATE_H
#include "State.h"

class MovableEntity;

class GameItem;

class AttackingState: public State{
    private:
        MovableEntity& objective;
        GameItem& weapon;
        int strength;
        int duration;

    public:
        AttackingState(MovableEntity& entity, MovableEntity& objective, GameItem& weapon, int strength, int duration);
        
        // Actualiza el estado notificando el paso del tiempo.
        void update(int time);

        bool isValid();

        void activate();

};

#endif
