#ifndef GAME_ITEM_H
#define GAME_ITEM_H
#include <string>
#include <vector>
#include "DamageDealer.h"
#include "DefenseDealer.h"

class GameItem{
    private:
        std::string name;
        int itemId;
        std::vector<int> acceptedSlots;
        DamageDealer damageDealer;
        DefenseDealer defenseDealer;
        int manaNeeded;

    public:
        GameItem();
        GameItem(std::string name, int itemId, int damageMin, int damageMax,
                    int defenseMin, int defenseMax, int range, int manaNeeded = 0);
        GameItem(GameItem&&);

        void addValidSlot(int slot);

        bool canBeEquipped(int slot);

        int getId();
        int getDamage();
        int getRange();
        int getDefense();
        int getManaNeeded();
};

#endif
