#include <sstream>
#include "Map.h"
#include "Creature.h"

// TODO: Not use constructor to initialize character

Map::Map() {
  loadMap();
}

void Map::loadMap() {
  this->height = 10;
  this->width = 10;

  // FIXME: Use loaded map
  int newMap[10][10] = {
      {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  };

  for (int row = 0; row < height; row++){
    for (int column = 0; column < width; column ++) {
      this->map[row][column] = newMap[row][column];
    }
  }
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
    case 0:
      return " ";
    case 1:
      return "T";
    case 2:
      return "P";
    case 3:
      return "C";
    default:
      return " ";
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
    //srand(time(0));
    //xRand = rand() % 5;
    //yRand = rand() % 5;
    xRand = 5;
    yRand = 5;
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

bool Map::isInbound(int x, int y) {
  return (x >= 0 && x <= this->width - 1 && y >= 0 && y <= this->height - 1);
}

bool Map::hasObstacle(int x, int y) const {
  return this->map[x][y] != 0;
}


