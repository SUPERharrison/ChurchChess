#include "move.h"

Move::Move(char rowStart, char colStart, char rowEnd, char colEnd) {
    rowStart_ = rowStart;
    colStart_ = colStart;
    rowEnd_ = rowEnd;
    colEnd_ = colEnd;
    enPassant_ = 0;
}

char Move::getRowStart() const {
    return rowStart_;
}

char Move::getColStart() const {
    return colStart_;
}

char Move::getRowEnd() const {
    return rowEnd_;
}

char Move::getColEnd() const {
    return colEnd_;
}

void Move::setEnPassant() {
    enPassant_ = 1;
}
