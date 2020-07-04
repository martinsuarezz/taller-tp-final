#ifndef WALKING_STATE_H
#define WALKING_STATE_H
#include "State.h"

class MovableEntity;

class WalkingState: public State{
    private:
        int x;
        int y;
        int xFinal;
        int yFinal;
        int duration;
        int direction;

    public:
        WalkingState(MovableEntity& entity, int xInitial, int yInitial, int xFinal, int yFinal, int duration, int direction);
        void update(int time);
        bool isValid();
        void activate();

};

#endif
