#ifndef TOSS_INTENION_H
#define TOSS_INTENION_H
#include "Intention.h"

class TossIntention: public Intention{
    private:
        int slot;
        
    public:
        TossIntention(int slot);
        ~TossIntention();

        void execute(Sender& game);
};

#endif
