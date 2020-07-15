#ifndef PICK_UP_INTENION_H
#define PICK_UP_INTENION_H
#include "Intention.h"


class PickUpIntention: public Intention{
    private:
        
    public:
        PickUpIntention();
        ~PickUpIntention();

        void execute(Sender& game);
};

#endif
