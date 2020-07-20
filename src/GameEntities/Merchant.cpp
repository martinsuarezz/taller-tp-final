#include "Merchant.h"
#include "MovableEntity.h"
#include "GameEntity.h"
#include "../GameMap.h"
#include "../Sender.h"
#include "../State/WalkingState.h"
#include "../State/IdleState.h"
#include "../Command/IdleCommand.h"
#include "../Constants.h"
#include "../Command/MoveCommand.h"
#include "../Command/ShowProductsCommand.h"
#include "../Configuration.h"
#include "../GameItem/GameItemFactory.h"
#include <time.h>
#include <random>
#include <stdexcept>
#include <vector>

Merchant::Merchant(Sender& game, GameMap& map, int entityId, int x, int y): 
                    MovableEntity(game, map, entityId, x, y, 0, false){  
    health.setMaxHealth(100);
    refreshProducts();
}

void Merchant::notifyMovement(int direction, int xNew, int yNew){
    game.addCommand(new MoveCommand(entityId, direction, xNew, yNew));
}

void Merchant::kill(MovableEntity& killer){
    game.removeMob(entityId);
}

void Merchant::update(int timeElapsed){
    Configuration& config = Configuration::getInstance();
    timePassed += timeElapsed;
    if (timePassed > config.getValue("merchant_refresh_sec")*MICROS_IN_SECOND){
        refreshProducts();
        timePassed = 0;
    }
}

void Merchant::refreshProducts(){
    products.clear();

    Configuration& config = Configuration::getInstance();
    std::default_random_engine generator(time(NULL));
    std::uniform_int_distribution<int> uniform(SWORD_ID, MAGIC_HAT_ID);
    std::normal_distribution<double> normal(140.0,20.0);
    uniform(generator);

    for (int i = 0; i < config.getValue("merchant_ammount_to_sell"); i++){
        int itemId = uniform(generator);
        int itemPrice = (int) normal(generator);
        products.push_back(itemId);
        products.push_back(itemPrice);
    }
}

void Merchant::notifyPlayerMovement(int xObj, int yObj){
}

bool Merchant::evadeAttack(){
    return true;
}

void Merchant::attackEntity(MovableEntity& other){
}

void Merchant::moveInventoryItem(int from, int to){}

void Merchant::notifyHealthUpdate(int newHealth){}

void Merchant::notifyExperienceUpdate(int newExperience){}

void Merchant::notifyLevelUpdate(int newLevel){}

void Merchant::notifyManaUpdate(int mana){}

void Merchant::notifyGoldUpdate(int gold){}

bool Merchant::addItem(int itemId, int slot){
    return false;
}

int Merchant::getDefense(int damage){
    return damage;
}

void Merchant::interact(MovableEntity& other){
    game.addCommand(new ShowProductsCommand(products));
}

void Merchant::buyItem(MovableEntity& buyer, int itemIndex){
    if (itemIndex * 2 >= (int) products.size())
        return;
    int itemWanted = products[itemIndex * 2];
    int itemPrice = products[itemIndex * 2 + 1];
    if (buyer.hasGoldAvailable(itemPrice) && buyer.addItem(itemWanted, -1)){
        buyer.removeGold(itemPrice);
        std::vector<int>::iterator it = products.begin() + itemIndex * 2;
        products.erase(it, it + 1);
    }
    refreshProducts();
    interact(buyer);
}

int Merchant::removeItem(int slot){
    std::runtime_error("No inventory");
    return -1;
}

void Merchant::revive(){}

Merchant::~Merchant(){}
