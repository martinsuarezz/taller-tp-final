#ifndef TIMEOUT_INTENION_H
#define TIMEOUT_INTENION_H
#include "Intention.h"

class TimeoutIntention: public Intention{
    private:
        
    public:
        TimeoutIntention();
        void execute(Sender& game);
};

#endif
