#ifndef WALKING_STATE_H
#define WALKING_STATE_H
#include "State.h"

class GameEntity;

class WalkingState: public State{
    private:
        int x;
        int y;
        int xFinal;
        int yFinal;
        int duration;
        int direction;

    public:
        WalkingState(GameEntity& entity, int xInitial, int yInitial, int xFinal, int yFinal, int duration, int direction);
        void update(int time);

};

#endif
