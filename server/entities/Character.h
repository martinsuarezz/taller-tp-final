#ifndef ARGENTUM_SERVER_CHARACTER_H_
#define ARGENTUM_SERVER_CHARACTER_H_

#include "../World.h"

class Character : public Entity {
 public:
  Character(World &world);

  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();
  bool isNextTo(Character *character);
  bool isNearFrom(Character *character);

  void react(Action action, Entity *sender) override = 0;

  void attack(Character *enemy);
  void receiveDamage(int damage);

  int getHealth();
  bool isAlive();

  virtual std::string toString() const = 0;

 protected:
  World &world;
  bool alive;

  int health;

  void dropItem();
};

#endif
