#ifndef ARGENTUM_SERVER_EVENT_H_
#define ARGENTUM_SERVER_EVENT_H_

#include <string>

// Cause
#define MOVE_UP_ID 1
#define MOVE_DOWN_ID 2
#define MOVE_RIGHT_ID 3
#define MOVE_LEFT_ID 4
#define ATTACK_ID 5
#define NEW_ENTITY_ID 0

// Effects
#define RECEIVE_DAMAGE_ID 4
#define DEAD_ID 5

enum Action {
  MOVE_LEFT,
  MOVE_RIGHT,
  MOVE_UP,
  MOVE_DOWN,
  ATTACK,
  NEW_ENTITY,
  RECEIVE_DAMAGE,
  DEAD,
  UNKNOWN
};

class Event {
 public:
  Event();
  Event(int senderId, Action action);
  Event(int senderId, int actionId);

  int getSenderId();
  Action getAction();
  static Action resolveAction(int actionId);

 private:
  int senderId;
  Action action;
};

#endif

