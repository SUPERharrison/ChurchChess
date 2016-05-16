#ifndef PAWN_H
#define PAWN_H

#include <stdexcept>
#include <vector>
#include "chessboard.h"
#include "move.h"

char isPawn(char piece);
std::vector<Move> getPawnMoves(const Chessboard&, char, char);

#endif
