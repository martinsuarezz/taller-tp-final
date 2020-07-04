#ifndef STOP_MOVE_INTENION_H
#define STOP_MOVE_INTENION_H
#include "Intention.h"

class StopMoveIntention: public Intention{
    private:
        
    public:
        StopMoveIntention();
        void execute(Sender& game);
};

#endif
