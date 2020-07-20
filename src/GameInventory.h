#ifndef GAME_INVENTORY_H
#define GAME_INVENTORY_H
#include <map>
#include "GameItem/GameItem.h"
#include "GameItem/GameItemFactory.h"

class Sender;

class GameInventory{
    private:
        std::map<int, GameItem> items;
        Sender& game;
        GameItemFactory itemFactory;
        GameItem bareHands;
        GameItem noArmor;
        int getEmptySlot();

    public:
        GameInventory(Sender& game);
        void moveItem(int from, int to);
        bool slotIsEmpty(int slot) const;
        bool addItem(int itemId, int slot);
        int removeItem(int slot);
        void equipItem(int itemId, int slot);
        void notifyDeath();
        GameItem& getWeapon();
        GameItem& getArmor();
        GameItem& getHelmet();
        GameItem& getShield();
};

#endif
