#ifndef GRAPHICAL_INTERFACE_H
#define GRAPHICAL_INTERFACE_H
#include <map>
#include "Item.h"
#include "Inventory.h"

class Texture;

class AssetsLoader;

class GraphicalInterface{
    private:
        AssetsLoader& assets;
        Texture& gui;
        Inventory inventory;
        std::map<int, Item> items;
        int inventorySlots;
        int selected;

    public:
        GraphicalInterface(AssetsLoader& assets);
        void render();
        void addItemInventory(int itemId, int position);
        void removeItemInventory(int position);
        void moveItemInventory(int from, int to);
        void addItemShop(int itemId, int price);
        void openShop();
        void closeShop();
        void moveItem(int from, int to);
        int getInventorySlot(int x, int y);
        bool slotIsInbound(int x, int y, int slot) const;
        void selectSlot(int slot);
        void resetSelection();
        ~GraphicalInterface();

};

#endif
