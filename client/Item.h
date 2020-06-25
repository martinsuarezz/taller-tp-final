#ifndef ITEM_H
#define ITEM_H
#include "Item.h"

class Texture;

class AssetsLoader;

class Item{
    private:
        Texture& texture;
        int itemId;

    public:
        Item(int itemId, AssetsLoader& assets);
        void render(int x, int y);
        int getItemId();
        //Item(Item&&);

};

#endif
