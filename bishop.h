#ifndef BISHOP_H
#define BISHOP_H

#include <stdexcept>
#include <vector>
#include "chessboard.h"
#include "move.h"

char isBishop(char piece);
std::vector<Move> getBishopMoves(const Chessboard&, char, char);

#endif
