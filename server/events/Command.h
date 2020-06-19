#ifndef ARGENTUM_SERVER_EVENT_H_
#define ARGENTUM_SERVER_EVENT_H_

#include <string>

#define MOVE_UP_ID 1
#define MOVE_DOWN_ID 2
#define MOVE_RIGHT_ID 3
#define MOVE_LEFT_ID 4
#define ATTACK_ID 5
#define NEW_ENTITY_ID 0

enum Action {
  MOVE_LEFT,
  MOVE_RIGHT,
  MOVE_UP,
  MOVE_DOWN,
  MAKE_ATTACK,
  UNKNOWN_ACTION,
};

enum Event {
  MOVE,
  NEW_ENTITY,
  ATTACK,
  RECEIVE_DAMAGE,
  DIE,
};

class Command {
 public:
  Command();
  Command(int senderId, Action action);
  Command(int senderId, int actionId);
  Command(int senderId, int actionId, int targetId);

  int getSenderId();
  Action getAction();
  int getTargetId();
  static Action resolveAction(int actionId);

 private:
  int senderId;
  Action action;
  int targetId;
};

#endif

