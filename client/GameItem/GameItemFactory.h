#ifndef GAME_ITEM_FACTORY_H 
#define GAME_ITEM_FACTORY_H
#include "GameItem.h"

class GameItemFactory{
    private:
        GameItem getItem(std::string name, int id);

    public:
        GameItemFactory();
        GameItem getBareHands();
        GameItem getNoArmor();
        GameItem getNoHelmet();
        GameItem getSword();
        GameItem getAxe();
        GameItem getHammer();
        GameItem getIceStaff();
        GameItem getElficFlute();
        GameItem getKnotStaff();
        GameItem getCrimpStaff();
        GameItem getSimpleBow();
        GameItem getCompoundBow();
        GameItem getLeatherArmor();
        GameItem getPlateArmor();
        GameItem getBlueTunic();
        GameItem getHood();
        GameItem getIronHelmet();
        GameItem getTurtleShield();
        GameItem getIronShield();
        GameItem getMagicHat();
        GameItem getItem(int id); 

};

#endif
