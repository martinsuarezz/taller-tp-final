#include "DefenseDealer.h"
#include "../RandomGenerator.h"
#include <iostream>

DefenseDealer::DefenseDealer(int minDefense, int maxDefense):
                            minDefense(minDefense), maxDefense(maxDefense){}

DefenseDealer::DefenseDealer(DefenseDealer&& other): minDefense(other.minDefense),
                            maxDefense(other.maxDefense){}


int DefenseDealer::getDefense(){
    RandomGenerator& random = RandomGenerator::getInstance();
    int defense = random(minDefense, maxDefense + 1);
    return defense;
}
