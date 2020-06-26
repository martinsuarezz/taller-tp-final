#ifndef ARGENTUM_SERVER_STATE_STATE_H_
#define ARGENTUM_SERVER_STATE_STATE_H_

#include "../entities/Entity.h"

class State {
 public:
  State() : timeElapsed(0), inProgress(true) {}
  virtual void update(Entity* entity, int dt) = 0;
 protected:
  int timeElapsed;
  bool inProgress;
};

#endif
