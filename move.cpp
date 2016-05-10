#include "move.h"

Move::Move(const Piece& piece, int row, int col) {
    piece_ = piece;
    row_ = row;
    col_ = col;
}

int Move::getRow() const {
    return row_;
}

int Move::getCol() const {
    return col_;
}
