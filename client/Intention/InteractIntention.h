#ifndef INTERACT_INTENION_H
#define INTERACT_INTENION_H
#include "Intention.h"


class InteractIntention: public Intention{
    private:
        
    public:
        InteractIntention();
        ~InteractIntention();

        void execute(Sender& game);
};

#endif
