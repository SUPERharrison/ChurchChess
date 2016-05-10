#ifndef MOVE_H
#define MOVE_H
#include "piece.h"

class Move {

  private:
      Piece piece_;
      int row_;
      int col_;

  public:
      explicit Move(const Piece&, int, int);
      int getRow() const;
      int getCol() const;

};

#endif
