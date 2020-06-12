#ifndef ARGENTUM__CHARACTER_H_
#define ARGENTUM__CHARACTER_H_

#include <string>
#include "Character.h"

class Player : public Character {

 public:
  Player(World& world, int id, std::string& name);

  std::string getName() const;

  int getLevel() const;
  int getExp() const;

  void react(int event, Entity* sender) override;

  std::string toString() const override;

  ~Player();
 private:
  std::string name;

  int level;
  int exp;
  int nextExp;
};

#endif