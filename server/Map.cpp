#include <sstream>
#include <fstream>
#include "Map.h"
#include "Creature.h"
#include "../utils/nlohmann/json.hpp"

Map::Map() {
  std::string filename("../map1.json");
  load(filename);
}

void Map::load(std::string& filename) {
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

std::string Map::draw() const {
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

std::string Map::drawObject(int object) const{
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

int Map::getObject(std::string str) const {
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

// Move to Game?
void Map::addPlayer(Player* character) {
  int xRand, yRand;

  do {
    srand(time(0));
    xRand = rand() % 5;
    yRand = rand() % 5;
  } while(this->map[xRand][yRand] != 0);

  map[xRand][yRand] = 2;

  character->setPosition(xRand, yRand);
}

void Map::addCreature(Creature* character) {
  int xRand, yRand;

  do {
    srand(time(0));
    xRand = rand() % 5;
    yRand = rand() % 5;
  } while(this->map[xRand][yRand] != 0);

  map[xRand][yRand] = 3;

  character->setPosition(xRand, yRand);
}

void Map::update(int actualX, int actualY, int nextX, int nextY, int type) {
  if(this->isInbound(nextX, nextY)) {
    this->map[actualX][actualY] = 0;
    this->map[nextX][nextY] = type;
  }
}

bool Map::isInbound(int x, int y) const {
  return (x >= 0 && x <= this->width - 1 && y >= 0 && y <= this->height - 1);
}

bool Map::hasObstacle(int x, int y) const {
  return this->map[x][y] != 0;
}


