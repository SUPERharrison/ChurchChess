#ifndef MOVE_H
#define MOVE_H

class Move {

  private:
      int x_;
      int y_;

  public:
      explicit Move();
      int getX() const;
      int getY() const;

};

#endif
