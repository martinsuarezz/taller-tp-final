#include "EventManager.h"

EventManager::EventManager() {

}

void EventManager::subscribe(Event event, Entity *observer) {
  observers[event].push_back(observer);
}

void EventManager::notify(Event event, Entity* notifier) {
  if(observers.count(event) > 0) {
    for (auto observer: observers.at(event))
      observer->react(event, notifier);
  }
}
