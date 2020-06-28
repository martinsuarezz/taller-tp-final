#ifndef ARGENTUM_SERVER_STATE_WALKINGSTATE_H_
#define ARGENTUM_SERVER_STATE_WALKINGSTATE_H_

#include "State.h"

#include "../Command.h"

class WalkingState : public State {
 public:
  WalkingState(Entity* entity, Action action);
  void update(float dt) override;
 private:
  Action action;
  void handleAction(Action action);
  void move(float inc);
  void moveLeft(float inc);
  void moveRight(float inc);
  void moveDown(float inc);
  void moveUp(float inc);
};

#endif
