#include "WalkingState.h"
#include "../GameEntity.h"
#include <stdexcept>
#include <iostream>

WalkingState::WalkingState(GameEntity& entity, int xInitial, int yInitial, int xFinal, int yFinal, int duration, int direction): 
                        State(entity), x(xInitial*100), y(yInitial*100), xFinal(xFinal*100), yFinal(yFinal*100), duration(duration), direction(direction){}

void WalkingState::update(int timeElapsed){
    if (duration == 0)
        throw std::runtime_error("Duration is 0");
    float xToMove = (xFinal - x) * timeElapsed / duration;
    float yToMove = (yFinal - y) * timeElapsed / duration;

    std::cout << "(x, y): " << x << " , " << y << std::endl;
    std::cout << "to move (x, y): " << xToMove << " , " << yToMove << std::endl;
    std::cout << "Final (x, y): " << xFinal << " , " << yFinal << std::endl;

    x += (int) xToMove;
    y += (int) yToMove;
    duration -= timeElapsed;
    entity.notifyMovement(direction, x, y);
}