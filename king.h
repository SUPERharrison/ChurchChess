#ifndef KING_H 
#define KING_H

#include <stdexcept>
#include <vector>
#include "chessboard.h"
#include "move.h"

char isKing(char piece);
std::vector<Move> getKingMoves(const Chessboard&, char, char);

#endif
