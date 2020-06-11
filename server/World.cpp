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

  for (auto& el : map["objects"].items()) {
    nlohmann::json obj = el.value();
    this->map[obj["x"]][obj["y"]] = getObject(obj["type"]);
  }

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

std::string World::drawObject(int object) const{
  switch(object) {
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

int World::getObject(std::string str) const {
  if(str == TREE_STR) {
    return TREE;
  } else if(str == PLAYER_STR) {
    return PLAYER;
  } else if(str == CREATURE_STR) {
    return  CREATURE;
  } else {
    return EMPTY;
  }
}

void World::addEntity(Entity *entity, int x, int y) {
  int xPos = x;
  int yPos = y;

  if(!isEmpty(x,y)) {
    do {
      xPos = x + 1;
      yPos = y + 1;
    } while(this->map[xPos][yPos] != 0);
  }

  map[xPos][yPos] = entity->getType();

  entity->setPosition(xPos, yPos);
  //entities.push_back(entity);
}

void World::moveTo(int nextY, int nextX, Entity *entity) {
  int actualX = entity->getX();
  int actualY = entity->getY();

  if(this->isInbound(nextX, nextY)) {
    this->map[actualX][actualY] = 0;
    this->map[nextX][nextY] = entity->getType();
  }
}

bool World::isInbound(int x, int y) const {
  return (x >= 0 && x <= this->width - 1 && y >= 0 && y <= this->height - 1);
}

bool World::isEmpty(int x, int y) const {
  return this->map[x][y] != 0;
}

void World::notify(int event, Entity *entity) {
//  for(auto entity: entities) {
//    //entity->react(event, entity);
//  }
}

