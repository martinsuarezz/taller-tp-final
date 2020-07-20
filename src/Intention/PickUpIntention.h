#ifndef PICK_UP_INTENION_H
#define PICK_UP_INTENION_H
#include "Intention.h"

// Clase que modela la intención de tomar un item del piso.

class PickUpIntention: public Intention{
    private:
        
    public:
        PickUpIntention();
        ~PickUpIntention();

        void execute(Sender& game);
};

#endif
