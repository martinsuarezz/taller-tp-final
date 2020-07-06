#ifndef IDLE_STATE_H
#define IDLE_STATE_H
#include "State.h"

class MovableEntity;

class IdleState: public State{
    private:
        
    public:
        IdleState(MovableEntity& entity);

        // Actualiza el estado. Intentará que la entidad
        // pasé al estado siguiente.
        void update(int time);

        // Siempre devuelve true.
        bool isValid();

        // Activa el estado notificando a la entidad de que
        // ahora se encuentra idle.
        void activate();

};

#endif
