#ifndef ARGENTUM_SERVER_STATE_IDLESTATE_H_
#define ARGENTUM_SERVER_STATE_IDLESTATE_H_

#include "State.h"

class IdleState : public State {
 public:
  void update(Entity* entity, int dt) override;
};

#endif
