#ifndef GAME_ITEM_FACTORY_H 
#define GAME_ITEM_FACTORY_H
#include "GameItem.h"

class GameItemFactory{
    private:

    public:
        GameItemFactory();
        GameItem getBareHands();
        GameItem getNoArmor();
        GameItem getNoHelmet();
        GameItem getItem(int id);

};

#endif
