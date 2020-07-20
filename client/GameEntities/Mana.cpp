#include "Mana.h"
#include "MovableEntity.h"
#include "../Constants.h"

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
    if (timeElapsed > MICROS_IN_SECOND){
        addMana(regenRate);
        timeElapsed -= MICROS_IN_SECOND; 
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
