#ifndef ARGENTUM_SERVER_STATE_STATE_H_
#define ARGENTUM_SERVER_STATE_STATE_H_

#include "../entities/Entity.h"

class State {
 public:
  explicit State(Entity* entity);
  virtual void update(float dt) = 0;
  int getX();
  int getY();
  char getType();
 protected:
  char type;
  Entity* entity;
  float timeElapsed;
  bool inProgress;
  int x;
  int y;
};

#endif
