#include <fstream>
#include <sstream>

#include "Map.h"
#include "../utils/nlohmann/json.hpp"
#include "World.h"

void Map::load(std::string& filename) {
  std::ifstream i(filename);
  nlohmann::json jsonMap;
  i >> jsonMap;

  this->width = jsonMap["width"];
  this->height = jsonMap["height"];

  for (int row = 0; row < height; row++) {
    for (int column = 0; column < width; column++) {
      this->tiles[width][height] = 0;
    }
  }

  i.close();
}

bool Map::isInbound(int x, int y) const {
  return (x >= 0 && x <= this->width - 1 && y >= 0 && y <= this->height - 1);
}

bool Map::isEmpty(int x, int y) const {
  return this->tiles[x][y] == 0;
}

void Map::update(Event event, Entity *entity) {
  switch(event) {
    case MOVE:
      tiles[entity->getPrevX()][entity->getPrevY()] = 0;
      tiles[entity->getX()][entity->getY()] = entity->getType();
      break;
    case ATTACK:
      break;
    case RECEIVE_DAMAGE:
      break;
    case DEAD:
      break;
  }
}

void Map::add(int x, int y, Entity *entity) {
  while(!isEmpty(x, y)) {
    srand(time(0));
    if (rand() % 2 == 0) {
      x = x + 1;
    } else {
      y = y + 1;
    }
  }

  entity->setPosition(x, y);

  tiles[x][y] = entity->getType();
}

// Just for testing
std::string Map::draw() const {
  std::stringstream ss;
  ss << "====================\n";
  for (int row = 0; row < height; row++){
    for (int column = 0; column < width; column ++) {
      ss << this->getASCII(tiles[column][row]) << " ";
    }

    ss << "\n";
  }
  ss << "====================\n";
  return ss.str();
}

std::string Map::getASCII(char type) const{
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