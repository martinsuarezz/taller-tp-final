#ifndef ARGENTUM_SERVER_ENTITY_H_
#define ARGENTUM_SERVER_ENTITY_H_

#include <vector>
#include "../Command.h"

class State;
class World;

class Entity {
 public:
  Entity(World &world, int x, int y);

  int getId() const;
  int getX() const;
  int getY() const;
  int getPrevX() const;
  int getPrevY() const;
  char getType() const;
  bool isDynamic() const;
  bool isSolid() const;
  int getVelocity() const;

  void setId(int id);
  void setPosition(int x, int y);
  void setState(State* state);

  virtual void react(Event event, Entity* sender) = 0;
  virtual void update(float dt) = 0;

  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();
  bool canMove(int x, int y);

  std::vector<Event>& getEvents();

 protected:
  World& world;

  int id{};

  int x;
  int y;
  int prevX;
  int prevY;

  char type{};
  bool solid{};
  bool dynamic{};
  int velocity{};

  State* state{};

  std::vector<Event> events;
};

#endif
