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
        WalkingState(MovableEntity& entity, int xInitial, int yInitial,
                    int xFinal, int yFinal, int duration, int direction);
        
        // Actualiza el estado notificando el movimiento de la entidad.
        void update(int time);

        // Devuelve true si la entidad se puede mover a la posición del estado.
        bool isValid();

        // Activa el estado actualizando la posición de la entidad.
        void activate();

};

#endif
