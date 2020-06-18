#include <fstream>
#include <sstream>

#include "Map.h"
#include "../utils/nlohmann/json.hpp"
#include "World.h"
#include "entities/Player.h"

void Map::load(std::string& filename) {
  std::ifstream i(filename);
  nlohmann::json jsonMap;
  i >> jsonMap;

  this->width = jsonMap["width"];
  this->height = jsonMap["height"];

  this->map = new Entity*[width * height];

  for (int row = 0; row < height; row++) {
    for (int column = 0; column < width; column++) {
      this->map[row * width + column] = nullptr;
    }
  }

  i.close();
}

void Map::notify(Action action, Entity *entity) {
  switch(action) {
    case MOVE_LEFT:
    case MOVE_RIGHT:
    case MOVE_UP:
    case MOVE_DOWN:
      this->move(entity);
      break;
    case DEAD:
      this->remove(entity);
      break;
    case NEW_ENTITY:
      this->add(entity);
      break;
    case ATTACK: break;
    case RECEIVE_DAMAGE: break;
    case UNKNOWN:break;
  }
}

void Map::move(Entity * entity) {
  if (this->canMove(entity->getX(), entity->getY())) {
    // Pick up item
    Entity* next = get(entity->getX(), entity->getY());
    if(next != nullptr && !next->isSolid() && entity->getType() == PLAYER) {
      auto* player = (Player*) entity;
      player->pickUp((Item*) next);
    }

    // Move entity
    this->set(entity->getPrevX(), entity->getPrevY(), nullptr);
    this->set(entity->getX(), entity->getY(), entity);
  } else {
    // Backward
    entity->setPosition(entity->getPrevX(), entity->getPrevY());
  }
}

void Map::remove(Entity* entity) {
  if (entity->getType() == CREATURE){
    this->set(entity->getX(), entity->getY(), nullptr);
  }
}

void Map::add(Entity *entity) {
  int x = entity->getX();
  int y = entity->getY();

  while(!isEmpty(x, y)) {
    srand(time(0));
    if (rand() % 2 == 0) {
      x = x + 1;
    } else {
      y = y + 1;
    }
  }

  entity->setPosition(x, y);
  this->set(x,y, entity);
}

void Map::set(int x, int y, Entity* entity) {
  this->map[y * width + x] = entity;
}

Entity* Map::get(int x, int y) const {
  return this->map[y * width + x];
}

bool Map::isInbound(int x, int y) const {
  return (x >= 0 && x <= this->width - 1 && y >= 0 && y <= this->height - 1);
}

bool Map::isEmpty(int x, int y) const {
  return this->get(x, y) == nullptr;
}

bool Map::canMove(int x, int y) const {
  return (this->isEmpty(x, y) || !this->get(x, y)->isSolid()) && this->isInbound(x, y);
}

// Just for testing
std::string Map::draw() const {
  std::stringstream ss;
  ss << "====================\n";
  for (int row = 0; row < height; row++){
    for (int column = 0; column < width; column ++) {
      if(this->get(column, row) != nullptr) {
        ss << this->get(column, row)->getType() << " ";
      } else {
        ss << EMPTY;
      }
    }

    ss << "\n";
  }
  ss << "====================\n";
  return ss.str();
}