#ifndef ARGENTUM_SERVER_ENTITY_H_
#define ARGENTUM_SERVER_ENTITY_H_

class Entity {
 public:
  Entity();

  int getId() const;
  int getX() const;
  int getY() const;
  int getPrevX() const;
  int getPrevY() const;

  virtual void setPosition(int x, int y);

  virtual void react(int event, Entity* sender) = 0;

  char getType();
 protected:
  int id;

  int x;
  int y;
  int prevX;
  int prevY;

  char type;

};

#endif
