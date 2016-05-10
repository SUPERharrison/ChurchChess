#include "move.h"

Move::Move() {
    x_ = 5;
    y_ = 0;
}

int Move::getX() const {
    return x_;
}

int Move::getY() const {
    return y_;
}
