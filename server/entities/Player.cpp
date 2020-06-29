#include <sstream>
#include "Player.h"
#include "Item.h"

Player::Player(World& world, int id, std::string& name, int x, int y) : Character(world, x, y) {
  this->id = id;
  this->name = name;
  this->type = PLAYER;
  this->health = 100;
  this->exp = 0;
  this->nextExp = 100;
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

void Player::react(Event event, Entity *sender) {

}

void Player::pickUp(Item* item) {
  this->inventory.addItem(item);
}

// Private methods

std::string Player::toString() const {
  std::stringstream ss;

  ss << "Id: " << this->id << " - "
     << "Nombre: " << this->name << " - "
     << "Vida: " << this->health << " - "
     << "Nivel: " << this->level << " - "
     << "Experiencia: " << this->exp << " - "
     << "Posicion X: " << this->x << " Y: " << this->y << " - "
     << "Inventario: " << this->inventory.toString();

  return ss.str();
}
