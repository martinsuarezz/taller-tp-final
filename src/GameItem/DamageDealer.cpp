#include "DamageDealer.h"
#include "../RandomGenerator.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

DamageDealer::DamageDealer(int minDamage, int maxDamage, int range, int duration):
                            minDamage(minDamage), maxDamage(maxDamage), 
                            range(range), duration(duration){}

DamageDealer::DamageDealer(DamageDealer&& other): minDamage(other.minDamage),
                            maxDamage(other.maxDamage), range(other.range),
                            duration(other.duration){}


int DamageDealer::getDamage(){
    RandomGenerator& random = RandomGenerator::getInstance();
    int damageDone = random(minDamage, maxDamage + 1);
    return damageDone;
}

int DamageDealer::getRange(){
    return range;
}

int DamageDealer::getDuration(){
    return duration;
}
