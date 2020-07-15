#include "Mana.h"
#include "MovableEntity.h"

#define MICROSECONDS_IN_SEC 1000000

Mana::Mana(MovableEntity& entity): depleted(0), maxMana(100), 
                        regenRate(0), entity(entity){}

void Mana::setMaxMana(int maxMana){
    this->maxMana = maxMana;
    entity.notifyManaUpdate(getMana());
}

void Mana::setManaRegen(int ManaRegen){
    this->regenRate = ManaRegen;
}

void Mana::changeMana(int value){
    depleted -= value;
    if (depleted > maxMana)
        depleted = maxMana;
    if (depleted < 0)
        depleted = 0;
    entity.notifyManaUpdate(getMana());
}

void Mana::regenerate(int time){
    timeElapsed += time;
    if (timeElapsed > MICROSECONDS_IN_SEC){
        addMana(regenRate);
        timeElapsed -= MICROSECONDS_IN_SEC; 
    }
}

void Mana::addMana(int plusMana){
    changeMana(plusMana);
}

void Mana::removeMana(int removed){
    changeMana(-removed);
}

int Mana::getMana(){
    return maxMana - depleted;
}
