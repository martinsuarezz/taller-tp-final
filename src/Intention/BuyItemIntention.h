#ifndef BUY_ITEM_INTENION_H
#define BUY_ITEM_INTENION_H
#include "Intention.h"

// Clase que modela la itnención de comprar
// un item de un comerciante.

class BuyItemIntention: public Intention{
    private:
        int itemIndex;
        
    public:
        BuyItemIntention(int itemIndex);
        ~BuyItemIntention();

        void execute(Sender& game);
};

#endif
