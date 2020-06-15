#ifndef ARGENTUM_SERVER_INVENTORY_H_
#define ARGENTUM_SERVER_INVENTORY_H_

#include <vector>
#include "entities/Item.h"

class Inventory {
 public:
  Inventory();

  void addItem(Item *item);

  std::string toString() const;

  ~Inventory();
 private:
  std::vector<Item*> items;
};

#endif
