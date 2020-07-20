#ifndef TOSS_INTENION_H
#define TOSS_INTENION_H
#include "Intention.h"

// Clase que modela la intención de un jugador de tirar un item de
// su inventario al piso.

class TossIntention: public Intention{
    private:
        int slot;
        
    public:
        TossIntention(int slot);
        ~TossIntention();

        void execute(Sender& game);
};

#endif
