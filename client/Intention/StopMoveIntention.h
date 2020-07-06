#ifndef STOP_MOVE_INTENION_H
#define STOP_MOVE_INTENION_H
#include "Intention.h"

// Clase que modela que el jugador detuvo su movimiento.

class StopMoveIntention: public Intention{
    private:
        
    public:
        StopMoveIntention();

        // Le notifica a la lógica del juego que el jugador se quiere detener.
        void execute(Sender& game);
};

#endif
