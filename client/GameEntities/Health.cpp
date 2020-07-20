#include "Health.h"
#include "MovableEntity.h"
#include "../Constants.h"

Health::Health(MovableEntity& entity): damage(0), maxHealth(100), 
                        regenRate(0), entity(entity){}

void Health::setMaxHealth(int maxHealth){
    this->maxHealth = maxHealth;
    entity.notifyHealthUpdate(getHealth());
}

void Health::setHealthRegen(int healthRegen){
    this->regenRate = healthRegen;
}

void Health::changeHealth(int value){
    damage -= value;
    if (damage > maxHealth)
        damage = maxHealth;
    if (damage < 0)
        damage = 0;
    entity.notifyHealthUpdate(getHealth());
}

void Health::regenerate(int time){
    timeElapsed += time;
    if (timeElapsed > MICROS_IN_SECOND){
        addHealth(regenRate);
        timeElapsed -= MICROS_IN_SECOND; 
    }
}

void Health::addHealth(int plusHealth){
    changeHealth(plusHealth);
}

void Health::dealDamage(int damageDealt){
    changeHealth(-damageDealt);
}

int Health::getHealth(){
    return maxHealth - damage;
}

int Health::getMaxHealth(){
    return maxHealth;
}
