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
#include <random>
#include "../GameItem/GameItemFactory.h"
#include <time.h>
#include <iostream>
#include <vector>

#define PRODUCTS_TO_SELL 3
#define REFRESH_SECONDS 10 

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
    timePassed += timeElapsed;
    if (timePassed > REFRESH_SECONDS * 1000000){
        refreshProducts();
        timePassed = 0;
    }
}

void Merchant::refreshProducts(){
    products.clear();
    std::default_random_engine generator(time(NULL));
    std::uniform_int_distribution<int> uniform(SWORD_ID, MAGIC_HAT_ID);
    std::normal_distribution<double> normal(140.0,20.0);
    uniform(generator);

    for (int i = 0; i < PRODUCTS_TO_SELL; i++){
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
    interact(buyer);
}

void Merchant::revive(){}

Merchant::~Merchant(){}
