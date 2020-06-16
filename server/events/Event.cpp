#include "Event.h"

Event::Event(int senderId, std::string &action) {
  this->senderId = senderId;
  this->action = action;
}

std::string& Event::getAction() {
  return action;
}

Action Event::resolve(std::string &action) {
  if(action == MOVE_STR) {
    return MOVE;
  } else if(action == ATTACK_STR) {
    return ATTACK;
  } else if(action == RECEIVE_DAMAGE_STR) {
    return RECEIVE_DAMAGE;
  } else if(action == NEW_ENTITY_STR) {
    return NEW_ENTITY;
  } else if(action == DEAD_STR) {
    return DEAD;
  } else {
    return UNKNOWN;
  }
}
