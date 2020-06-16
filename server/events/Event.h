#ifndef ARGENTUM_SERVER_EVENT_H_
#define ARGENTUM_SERVER_EVENT_H_

#include <string>

// Cause
#define MOVE_STR "move"
#define ATTACK_STR "attack"
#define NEW_ENTITY_STR "new_entity"

// Effects
#define RECEIVE_DAMAGE_STR "receive_damage"
#define DEAD_STR "dead"

enum Action {
  MOVE,
  ATTACK,
  NEW_ENTITY,
  RECEIVE_DAMAGE,
  DEAD,
  UNKNOWN
};

class Event {
 public:
  Event(int senderId, std::string& action);
  std::string& getAction();
  static Action resolve(std::string& action);

 private:
  int senderId;
  std::string action;
};

#endif

