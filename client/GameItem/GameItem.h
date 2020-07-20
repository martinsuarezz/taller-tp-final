#ifndef GAME_ITEM_H
#define GAME_ITEM_H
#include <string>
#include <vector>
#include "DamageDealer.h"
#include "DefenseDealer.h"

// Clase que modela un item del juego
// desde la parte lógica del juego.

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
                    int defenseMin, int defenseMax, int range, int duration, int manaNeeded = 0);
        GameItem(GameItem&&);

        // Agrega un lugar válido donde es posible equipar el item.
        void addValidSlot(int slot);

        // Chequea si se puede equipar en dicho lugar del inventario.
        bool canBeEquipped(int slot);

        // Obtiene los distintos valores del item.
        int getId();
        int getDamage();
        int getRange();
        int getDefense();
        int getManaNeeded();
        int getDuration();
};

#endif
