#ifndef ARGENTUM_SERVER_STATE_WALKINGSTATE_H_
#define ARGENTUM_SERVER_STATE_WALKINGSTATE_H_

#include "State.h"

#include "../Command.h"

class WalkingState : public State {
 public:
  explicit WalkingState(Action action);
  void update(Entity* entity, int dt) override;
 private:
  Action action;
};

#endif
