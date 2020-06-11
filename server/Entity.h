#ifndef ARGENTUM_SERVER_ENTITY_H_
#define ARGENTUM_SERVER_ENTITY_H_

class Entity {
 public:
  Entity();

  int getId() const;
  int getX() const;
  int getY() const;

  void setPosition(int x, int y);

  //virtual void react(Event event, Entity* sender) = 0;

  int getType();
 protected:
  int id;
  int x;
  int y;
  int type;

};

#endif
