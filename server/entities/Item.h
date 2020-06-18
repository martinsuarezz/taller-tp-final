#ifndef ARGENTUM_SERVER_ENTITIES_ITEM_H_
#define ARGENTUM_SERVER_ENTITIES_ITEM_H_

#include "Entity.h"

class Item : public Entity {
 public:
  Item();

  void react(Action action, Entity* sender) override;
};

#endif

