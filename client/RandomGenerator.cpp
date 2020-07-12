#include "RandomGenerator.h"
#include <stdlib.h> 
#include <time.h>

RandomGenerator::RandomGenerator(){
    srand(time(0));
}

RandomGenerator& RandomGenerator::getInstance(){
    static RandomGenerator instance;
    return instance;
}

int RandomGenerator::getValue(int maxNumber) const{
    return rand() % maxNumber;
}

int RandomGenerator::getValue(int minNumber, int maxNumber) const{
    return getValue(maxNumber - minNumber) + minNumber;
}

int RandomGenerator::operator()(int maxNumber) const{
    return getValue(maxNumber);
}

int RandomGenerator::operator()(int minNumber, int maxNumber) const{
    return getValue(minNumber, maxNumber);
}