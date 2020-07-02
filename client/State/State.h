#ifndef STATE_H
#define STATE_H

class GameEntity;

class State{
    protected:
        GameEntity& entity;

    public:
        State(GameEntity& entity);
        virtual void update(int time) = 0;
        //~State();

};

#endif
