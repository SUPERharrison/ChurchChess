#ifndef ROOK_H 
#define ROOK_H

#include <stdexcept>
#include <vector>
#include "chessboard.h"
#include "move.h"

char isRook(char piece);
vector<Move> getRookMoves(const Chessboard&, char, char);

#endif
