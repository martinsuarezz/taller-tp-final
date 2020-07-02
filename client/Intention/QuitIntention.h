#ifndef QUIT_INTENION_H
#define QUIT_INTENION_H
#include "Intention.h"

class QuitIntention: public Intention{
    private:
        
    public:
        QuitIntention();
        void execute(Sender& game);
};

#endif
