#ifndef INTERACT_INTENION_H
#define INTERACT_INTENION_H
#include "Intention.h"

// Clase que modela la intención del jugador de interaccionar
// con un NPC.

class InteractIntention: public Intention{
    private:
        
    public:
        InteractIntention();
        ~InteractIntention();

        void execute(Sender& game);
};

#endif
