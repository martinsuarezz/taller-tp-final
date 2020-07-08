#include "DamageDealer.h"
#include <stdlib.h>
#include <time.h>

DamageDealer::DamageDealer(int minDamage, int maxDamage, int range):
                            minDamage(minDamage), maxDamage(maxDamage), 
                            range(range){}

DamageDealer::DamageDealer(DamageDealer&& other): minDamage(other.minDamage),
                            maxDamage(other.maxDamage), range(other.range){}


int DamageDealer::getDamage(){
    srand (time(NULL));
    int damageSpread = maxDamage - minDamage;
    return (rand() % damageSpread) + minDamage;
}

int DamageDealer::getRange(){
    return range;
}