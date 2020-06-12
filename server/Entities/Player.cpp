#include <sstream>
#include "Player.h"

Player::Player(World& world, int id, std::string& name) : Character(world) {
  this->id = id;
  this->name = name;
  this->type = PLAYER;
  this->level = 1;
}

Player::~Player() {

}

std::string Player::getName() const {
  return this->name;
}

int Player::getLevel() const {
  return this->level;
}

int Player::getExp() const {
  return this->exp;
}

void Player::react(int event, Entity *sender) {
  switch(event) {
    case 0:
      break;
  }
}

std::string Player::toString() const {
  std::stringstream ss;

  ss << "Id: " << this->id << " - "
     << "Nombre: " << this->name << " - "
     << "Nivel: " << this->level << " - "
     << "Experiencia: " << this->exp << " - "
     << "Posicion X: " << this->x << " Y: " << this->y;

  return ss.str();
}