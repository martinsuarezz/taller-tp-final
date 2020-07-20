#ifndef MOVE_INTENION_H
#define MOVE_INTENION_H
#include "Intention.h"

// Clase que modela intención de movimiento.

class MoveIntention: public Intention{
    private:
        int direction;
        
    public:
        // Recibe la dirección a donde se desea mover.
        MoveIntention(int direction);

        // Ejecuta la intención, indicandole al juego que el jugador
        // se quiere mover.
        void execute(Sender& game);
};

#endif
