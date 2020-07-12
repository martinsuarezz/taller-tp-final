#include "DamageDealer.h"
#include "../RandomGenerator.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

DamageDealer::DamageDealer(int minDamage, int maxDamage, int range):
                            minDamage(minDamage), maxDamage(maxDamage), 
                            range(range){}

DamageDealer::DamageDealer(DamageDealer&& other): minDamage(other.minDamage),
                            maxDamage(other.maxDamage), range(other.range){}


int DamageDealer::getDamage(){
    RandomGenerator& random = RandomGenerator::getInstance();
    int damageDone = random(minDamage, maxDamage + 1);
    std::cout << "Done " << damageDone << " damage!" << std::endl;
    return damageDone;
}

int DamageDealer::getRange(){
    return range;
}
