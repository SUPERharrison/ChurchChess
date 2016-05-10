#include "chessboard.h"

Chessboard::Chessboard() {
    pieces_.push_back(Piece("Not a Rook", 1, 1));
}

std::vector<Move> Chessboard::getMoves() const {
    std::vector<Move> v;
    return v;
}
