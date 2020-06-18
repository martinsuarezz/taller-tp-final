#include "Event.h"

Event::Event() {}

Event::Event(int senderId, Action action) {
  this->senderId = senderId;
  this->action = action;
}

Event::Event(int senderId, int actionId) {
  this->senderId = senderId;
  this->action = resolveAction(actionId);
}

Action Event::resolveAction(int actionId) {
  if (actionId == MOVE_UP_ID) {
    return MOVE_UP;
  } else if (actionId == MOVE_DOWN_ID) {
    return MOVE_DOWN;
  } else if (actionId == MOVE_RIGHT_ID) {
    return MOVE_RIGHT;
  } else if (actionId == MOVE_LEFT_ID) {
    return MOVE_LEFT;
  } else if (actionId == ATTACK_ID) {
    return ATTACK;
  } else if (actionId == NEW_ENTITY_ID) {
    return NEW_ENTITY;
  } else {
    return UNKNOWN;
  }
}

Action Event::getAction() {
  return this->action;
}

int Event::getSenderId() {
  return this->senderId;
}