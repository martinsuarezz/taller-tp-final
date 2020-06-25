#ifndef GRAPHICAL_INTERFACE_H
#define GRAPHICAL_INTERFACE_H
#include <map>
#include "Item.h"

class Texture;

class AssetsLoader;

class GraphicalInterface{
    private:
        AssetsLoader& assets;
        Texture& gui;
        std::map<int, Item> items;
        int inventorySlots;
        int selected;
        int getX(int slot) const;
        int getY(int slot) const;

    public:
        GraphicalInterface(AssetsLoader& assets);
        void render();
        void addItem(int itemId, int position);
        void removeItem(int position);
        void moveItem(int from, int to);
        int getInventarySlot(int x, int y);
        bool slotIsInbound(int x, int y, int slot) const;
        void selectSlot(int slot);
        void resetSelection();
        ~GraphicalInterface();

};

#endif
