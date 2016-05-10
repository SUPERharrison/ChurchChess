#include "piece.h"

Piece::Piece(std::string name) {
    name_ = name;
}

std::vector<Move> Piece::getMovesMask() const {
    std::vector<Move> v;
    return v;
}
