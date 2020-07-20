#ifndef MOVE_ITEM_INTENION_H
#define MOVE_ITEM_INTENION_H
#include "Intention.h"

// Clase que modela la intención de mover un item
// del inventario de un slot a otro.

class MoveItemIntention: public Intention{
    private:
        int from;
        int to;
        
    public:
        MoveItemIntention(int from, int to);
        ~MoveItemIntention();

        // Avisa al juego que el jugador quiere
        // mover un item del inventario.
        void execute(Sender& game);
};

#endif
