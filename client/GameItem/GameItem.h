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

    public:
        GameItem();
        GameItem(std::string name, int itemId, int damageMin, int damageMax,
                    int defenseMin, int defenseMax, int range);
        GameItem(GameItem&&);

        void addValidSlot(int slot);

        bool canBeEquipped(int slot);

        int getId();
        int getDamage();
        int getRange();
        int getDefense();


};

#endif
