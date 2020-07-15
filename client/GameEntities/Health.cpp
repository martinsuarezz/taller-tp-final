#include "Health.h"
#include "MovableEntity.h"

#define MICROSECONDS_IN_SEC 1000000

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
    if (timeElapsed > MICROSECONDS_IN_SEC){
        addHealth(regenRate);
        timeElapsed -= MICROSECONDS_IN_SEC; 
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