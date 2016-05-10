#ifndef CHESSBOARD_H 
#define CHESSBOARD_H

#include <string>
#include <vector>
#include "piece.h"
#include "move.h"

class Chessboard {

  private:
      std::vector<Piece> pieces_;

  public:
      Chessboard();
      std::vector<Move> getMoves() const;

};

#endif
