#ifndef ARGENTUM_SERVER_STATE_STATE_H_
#define ARGENTUM_SERVER_STATE_STATE_H_

#include "../entities/Entity.h"

class State {
 public:
  State() : timeElapsed(0), inProgress(true), x(0), y(0) {}
  virtual void update(Entity* entity, float dt) = 0;
  int getX();
  int getY();
 protected:
  float timeElapsed;
  bool inProgress;
  int x;
  int y;
};

#endif
