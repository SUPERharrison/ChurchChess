#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include "move.h"

class Piece {

  private:
      std::string name_;

  public:
      explicit Piece(std::string);
      std::vector<Move> getMovesMask() const;

};

#endif
