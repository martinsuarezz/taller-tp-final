#ifndef ARGENTUM_SERVER_EVENTS_EVENTMANAGER_H_
#define ARGENTUM_SERVER_EVENTS_EVENTMANAGER_H_

#include <vector>
#include <map>
#include "Command.h"
#include "../entities/Entity.h"

class EventManager {
 public:
  EventManager();
  void subscribe(Event event, Entity* observer);
  void notify(Event event, Entity* notifier);

 private:
  std::map<Event, std::vector<Entity*>> observers;
};

#endif
