#ifndef ARGENTUM_SERVER_CHARACTER_H_
#define ARGENTUM_SERVER_CHARACTER_H_

#include "../World.h"

class Character : public Entity {
 public:
  Character(World &world);

  void move(int nextX, int nextY);
  bool isNextTo(Character *character);
  bool isNearFrom(Character* character);

  void react(Event event, Entity* sender) override = 0;

  void attack(Character *enemy);
  void receiveDamage(int damage);

  int getHealth();
  bool isAlive();

  virtual std::string toString() const = 0;
 protected:
  World& world;
  bool alive;

  int health;
};

#endif
