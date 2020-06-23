#ifndef ARGENTUM_SERVER_ENTITY_H_
#define ARGENTUM_SERVER_ENTITY_H_

#include <vector>
#include "../Command.h"

class Entity {
 public:
  Entity();

  int getId() const;
  int getX() const;
  int getY() const;
  int getPrevX() const;
  int getPrevY() const;
  char getType() const;
  bool isDynamic() const;
  bool isSolid() const;

  void setId(int id);
  void setPosition(int x, int y);

  virtual void react(Event event, Entity* sender) = 0;

  std::vector<Event>& getEvents();

 protected:
  int id;

  int x;
  int y;
  int prevX;
  int prevY;

  char type;
  bool solid;
  bool dynamic;

  std::vector<Event> events;
};

#endif
