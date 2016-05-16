#ifndef KNIGHT_H
#define KNIGHT_H

#include <stdexcept>
#include <vector>
#include "chessboard.h"
#include "move.h"

char isKnight(char piece);
std::vector<Move> getKnightMoves(const Chessboard&, char, char);

#endif
