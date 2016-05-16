#include "move.h"

Move::Move(char rowStart, char colStart, char rowEnd, char colEnd) {
    rowStart_ = rowStart;
    colStart_ = colStart;
    rowEnd_ = rowEnd;
    colEnd_ = colEnd;
    check_ = 0;
    enPassant_ = -1;
    enPassantTaken_ = 0;
    castling_ = 0;
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

void Move::setCheck() {
    check_ = 1;
}

char Move::getCheck() const {
    return check_;
}

void Move::setEnPassant() {
    enPassant_ = colEnd_;
}

char Move::getEnPassant() const {
    return enPassant_;
}

void Move::setEnPassantTaken() {
    enPassantTaken_ = 1;
}

char Move::getEnPassantTaken() const {
    return enPassantTaken_;
}

void Move::setCastling() {
    castling_ = 1;
}

char Move::getCastling() const {
    return castling_;
}
