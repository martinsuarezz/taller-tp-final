#ifndef ARGENTUM_SERVER_STATE_IDLESTATE_H_
#define ARGENTUM_SERVER_STATE_IDLESTATE_H_

#include "State.h"

class IdleState : public State {
 public:
  explicit IdleState(Entity* entity);
  void update(float dt) override;
};

#endif
