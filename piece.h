#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>

class Piece {

  private:
      std::string name_;
      int row_;
      int col_;
      int moves_;

  public:
      explicit Piece();
      explicit Piece(std::string, int, int);
      explicit Piece(const Piece&);

};

#endif
