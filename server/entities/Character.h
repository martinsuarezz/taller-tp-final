#ifndef ARGENTUM_SERVER_CHARACTER_H_
#define ARGENTUM_SERVER_CHARACTER_H_

#include "../World.h"
#include "../state/State.h"

class Character : public Entity {
 public:
  Character(World &world, int x, int y);

  bool isNextTo(Character *character);
  bool isNearFrom(Character *character);

  void react(Event event, Entity *sender) override = 0;
  void update(float dt) override;

  void attack(Character *enemy);
  void receiveDamage(int damage);

  int getHealth();
  bool isAlive();

  virtual std::string toString() const = 0;

 protected:
  bool alive;

  int health;

  void dropItem();
};

#endif
