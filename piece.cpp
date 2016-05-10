#include "piece.h"

Piece::Piece() {
    name_ = "default";
    row_ = 0;
    col_ = 0;
    moves_ = 0;
}

Piece::Piece(std::string name, int row, int col) {
    name_ = name;
    row_ = row;
    col_ = col;
    moves_ = 0;
}

Piece::Piece(const Piece& piece) {
    name_ = piece.name_;
    row_ = piece.row_;
    col_ = piece.col_;
    moves_ = piece.moves_;
}
