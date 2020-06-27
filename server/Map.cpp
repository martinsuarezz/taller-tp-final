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

void Map::notify(Event event, Entity *entity) {
  switch(event) {
    case MOVE:
      this->move(entity);
      break;
    case DIE:
      this->remove(entity);
      break;
    case NEW_ENTITY:
      this->add(entity);
      break;
    case REMOVE_ENTITY:
      this->remove(entity);
      break;
    case RECEIVE_DAMAGE:
      break;
    case ATTACK:break;
  }
}

void Map::move(Entity * entity) {
  int x = entity->getX() / 100;
  int y = entity->getY() / 100;

  int prevX = entity->getPrevX() / 100;
  int prevY = entity->getPrevY() / 100;

  if (this->canMove(x, y)) {
    // Pick up item
    Entity* next = get(x, y);
    if(next != nullptr && !next->isSolid() && entity->getType() == PLAYER) {
      auto* player = (Player*) entity;
      player->pickUp((Item*) next);
    }

    // Move entity
    this->set(prevX, prevY, nullptr);
    this->set(x, y, entity);
  } else {
    // Backward
    entity->setPosition(entity->getPrevX(), entity->getPrevY());
  }
}

void Map::remove(Entity* entity) {
  this->set(entity->getX(), entity->getY(), nullptr);
}

void Map::add(Entity *entity) {
  int x = entity->getX() / 100;
  int y = entity->getY() / 100;

  while(!isEmpty(x, y)) {
    srand(time(0));
    if (rand() % 2 == 0) {
      x = x + 1;
    } else {
      y = y + 1;
    }
  }

  entity->setPosition(x * 100, y * 100);
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
  return this->isInbound(x, y) && (this->isEmpty(x, y) || !this->get(x, y)->isSolid());
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
        ss << EMPTY << " ";
      }
    }

    ss << "\n";
  }
  ss << "====================\n";
  return ss.str();
}