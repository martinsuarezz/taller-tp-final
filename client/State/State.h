#ifndef STATE_H
#define STATE_H

class MovableEntity;

class State{
    protected:
        MovableEntity& entity;

    public:
        State(MovableEntity& entity);
        virtual void update(int time) = 0;
        virtual bool isValid() = 0;
        virtual void activate() = 0;

};

#endif
