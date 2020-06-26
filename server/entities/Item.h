#ifndef ARGENTUM_SERVER_ENTITIES_ITEM_H_
#define ARGENTUM_SERVER_ENTITIES_ITEM_H_

#include "Entity.h"

class Item : public Entity {
 public:
  Item(int x, int y);

  void react(Event event, Entity* sender) override;
  void update(float dt) override;
};

#endif

