#include "Item.h"
#include "Texture.h"
#include "AssetsLoader.h"
#include <string>

Item::Item(int itemId, AssetsLoader& assets): texture(assets.getTexture("item" + std::to_string(itemId))), itemId(itemId){}

void Item::render(int x, int y){
    texture.render(x, y);
}

int Item::getItemId(){
    return itemId;
}

//Item::Item(Item&& other): texture(other.texture), itemId(other.itemId){}