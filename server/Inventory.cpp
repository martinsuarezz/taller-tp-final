#include <sstream>
#include "Inventory.h"

Inventory::Inventory() {

}

Inventory::~Inventory() {

}

void Inventory::addItem(Item* item) {
  items.push_back(item);
}
std::string Inventory::toString() const {
  std::stringstream ss;

  for(int i = 0; i < items.size(); i++) {
    ss << items[i]->getType() << " ";
  }

  return ss.str();
}
