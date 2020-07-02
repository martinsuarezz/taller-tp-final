#ifndef MOVE_INTENION_H
#define MOVE_INTENION_H
#include "Intention.h"

class MoveIntention: public Intention{
    private:
        int direction;
        
    public:
        MoveIntention(int direction);
        void execute(Sender& game);
};

#endif
