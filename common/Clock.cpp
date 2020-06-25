#include "Clock.h"
#include <chrono>

Clock::Clock(){}

void Clock::start(){
  startTime = std::chrono::steady_clock::now();
}

void Clock::stop(){
  endTime = std::chrono::steady_clock::now();
}

int Clock::getDuration(){
  return std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
}