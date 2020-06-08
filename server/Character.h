#ifndef ARGENTUM_SERVER_CHARACTER_H_
#define ARGENTUM_SERVER_CHARACTER_H_

class Character {

 public:
  Character();

  int getId() const;

  int getX() const;
  int getY() const;

  void setPosition(int x, int y);

  bool isNextTo(Character *character);
  bool isNearFrom(Character* character);

 protected:
  int id;

  int x;
  int y;
};

#endif
