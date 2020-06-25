#include <chrono>

class Clock{
 private:
  int duration;
  std::chrono::steady_clock::time_point startTime;
  std::chrono::steady_clock::time_point endTime;

 public:
  Clock();
  void start();
  void stop();
  int getDuration();
};