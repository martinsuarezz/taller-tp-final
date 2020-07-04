#ifndef IDLE_STATE_H
#define IDLE_STATE_H
#include "State.h"

class MovableEntity;

class IdleState: public State{
    private:
        
    public:
        IdleState(MovableEntity& entity);
        void update(int time);
        bool isValid();
        void activate();

};

#endif
