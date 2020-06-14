#ifndef ARGENTUM_SERVER_ENTITY_H_
#define ARGENTUM_SERVER_ENTITY_H_

#include "../Event.h"
class Entity {
 public:
  Entity();

  int getId() const;
  int getX() const;
  int getY() const;
  int getPrevX() const;
  int getPrevY() const;

  void setId(int id);
  void setPosition(int x, int y);

  virtual void react(Event event, Entity* sender) = 0;

  char getType();
  bool isDynamic();
  bool isSolid();

 protected:
  int id;

  int x;
  int y;
  int prevX;
  int prevY;

  char type;
  bool solid;
  bool dynamic;

};

#endif
