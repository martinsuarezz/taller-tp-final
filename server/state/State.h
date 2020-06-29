#ifndef ARGENTUM_SERVER_STATE_STATE_H_
#define ARGENTUM_SERVER_STATE_STATE_H_

#include "../entities/Character.h"

class State {
 public:
  explicit State(Character* entity);
  virtual void update(float dt) = 0;
  int getX();
  int getY();
  char getType();
 protected:
  char type;
  Character* character;
  float timeElapsed;
  bool inProgress;
  int x;
  int y;
};

#endif
