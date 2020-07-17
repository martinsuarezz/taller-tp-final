#include "GoldContainer.h"
#include "MovableEntity.h"

GoldContainer::GoldContainer(MovableEntity& entity): 
                        goldAmmount(0), safeGold(100), entity(entity){}

void GoldContainer::add(int ammount){
    changeAmmount(ammount);
}

void GoldContainer::remove(int ammount){
    changeAmmount(-ammount);
}

void GoldContainer::changeAmmount(int ammount){
    goldAmmount += ammount;
    if (goldAmmount > getMaxGold())
        goldAmmount = getMaxGold();
    entity.notifyGoldUpdate(goldAmmount);
}

bool GoldContainer::areAvailable(int ammount){
    return goldAmmount >= ammount;
}

int GoldContainer::getMaxGold(){
    return safeGold * 1.5;
}

void GoldContainer::notifyDeath(){
    if (goldAmmount > safeGold)
        remove(goldAmmount - safeGold);
}
