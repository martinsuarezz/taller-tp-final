#include "Command.h"

Command::Command() {}

Command::Command(int senderId, Action action) {
  this->senderId = senderId;
  this->action = action;
  this->targetId = 0;
}

Command::Command(int senderId, int actionId, int targetId) {
  this->senderId = senderId;
  this->action = resolveAction(actionId);
  this->targetId = targetId;
}

Command::Command(int senderId, int actionId) {
  this->senderId = senderId;
  this->action = resolveAction(actionId);
  this->targetId = 0;
}

Action Command::resolveAction(int actionId) {
  if(actionId == JOIN_ID) {
    return JOIN;
  } else if  (actionId == MOVE_UP_ID) {
    return MOVE_UP;
  } else if (actionId == MOVE_DOWN_ID) {
    return MOVE_DOWN;
  } else if (actionId == MOVE_RIGHT_ID) {
    return MOVE_RIGHT;
  } else if (actionId == MOVE_LEFT_ID) {
    return MOVE_LEFT;
  } else if (actionId == ATTACK_ID) {
    return MAKE_ATTACK;
  } else if (actionId == DISCONNECT_ID) {
    return DISCONNECT;
  } else {
    return UNKNOWN_ACTION;
  }
}

Action Command::getAction() {
  return this->action;
}

int Command::getSenderId() {
  return this->senderId;
}

int Command::getTargetId() {
  return this->targetId;
}
