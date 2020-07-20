#include "Item.h"
#include "Texture.h"
#include "AssetsLoader.h"
#include "Configuration.h"
#include <string>

Item::Item(int itemId, AssetsLoader& assets):
            texture(assets.getTexture("item" + std::to_string(itemId) + 
                                        "_icon_inv")),
            itemId(itemId){

    Configuration& config = Configuration::getInstance();
    texture.setWidth(config.getValue("inv_x_slot_size_px"));
    texture.setHeight(config.getValue("inv_y_slot_size_px"));
}

void Item::render(int x, int y){
    texture.render(x, y);
}

int Item::getItemId() const{
    return itemId;
}
