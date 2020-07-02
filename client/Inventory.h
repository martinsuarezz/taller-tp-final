#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include <map>

class AssetsLoader;

class Inventory{
    private:
        AssetsLoader& assets;
        std::map<int, Item> items;
        int slots;
        int selected;
        int getX(int slot) const;
        int getY(int slot) const;

    public:
        Inventory(AssetsLoader& assets);
        void render();
        void addItem(int itemId, int position);
        void removeItem(int position);
        void moveItem(int from, int to);
        int getSlot(int x, int y);
        bool slotIsInbound(int x, int y, int slot) const;
        void selectSlot(int slot);
        void handleLeftClick(int x, int y);
        void resetSelection();
        ~Inventory();
};

#endif
