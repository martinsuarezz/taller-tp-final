#include <sstream>
#include <fstream>
#include "../utils/nlohmann/json.hpp"
#include "World.h"

World::World() {
  std::string filename("../map1.json");
  load(filename);
}

void World::load(std::string& filename) {
  std::ifstream i(filename);
  nlohmann::json map;
  i >> map;

  this->width = map["width"];
  this->height = map["height"];

  for (int row = 0; row < height; row++){
    for (int column = 0; column < width; column ++) {
      this->map[width][height] = 0;
    }
  }

  // FIXME:
  //  for (auto& el : map["objects"].items()) {
  //    nlohmann::json obj = el.value();
  //    this->map[obj["x"]][obj["y"]] = getObject(obj["type"]);
  //  }

  i.close();
}

std::string World::draw() const {
  std::stringstream ss;

  ss << "====================\n";

  for (int row = 0; row < height; row++){
    for (int column = 0; column < width; column ++) {
        ss << this->drawObject(map[column][row]) << " ";
    }

    ss << "\n";
  }

  ss << "====================\n";

  return ss.str();
}

std::string World::drawObject(char type) const{
  switch(type) {
    case EMPTY:
      return " ";
    case TREE:
      return "T";
    case PLAYER:
      return "P";
    case CREATURE:
      return "C";
    default:
      return " ";
  }
}

void World::addEntity(int x, int y, Entity *entity) {
  while(!isEmpty(x, y)) {
    srand(time(0));
    if (rand() % 2 == 0) {
      x = x + 1;
    } else {
      y = y + 1;
    }
  }

  map[x][y] = entity->getType();

  entity->setPosition(x, y);
  entities.push_back(entity);
}

void World::updateMap(Entity *entity) {
  map[entity->getPrevX()][entity->getPrevY()] = 0;
  map[entity->getX()][entity->getY()] = entity->getType();
}

bool World::isInbound(int x, int y) const {
  return (x >= 0 && x <= this->width - 1 && y >= 0 && y <= this->height - 1);
}

bool World::isEmpty(int x, int y) const {
  return this->map[x][y] == 0;
}

// TODO: Use Entity matrix to check
bool World::canMove(int x, int y) const {
  return this->isEmpty(x, y) && this->isInbound(x, y);
}

void World::notify(int event, Entity *sender) {
  if(event == 0) {
    this->updateMap(sender);
  }

  // notify entities
  for(auto entity: entities) {
    entity->react(event, sender);
  }
}
