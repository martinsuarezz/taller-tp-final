#ifndef ARGENTUM_SERVER_INVENTORY_H_
#define ARGENTUM_SERVER_INVENTORY_H_

#include <vector>
#include "Entities/Item.h"

class Inventory {
 public:
  int addItem(Item *item);
 private:
  std::vector<Item*> items;
};

#endif
