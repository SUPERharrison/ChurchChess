#ifndef QUEEN_H 
#define QUEEN_H 

#include <stdexcept>
#include <vector>
#include "move.h"
#include "chessboard.h"

char isQueen(char piece);
std::vector<Move> getQueenMoves(const Chessboard&, char, char);

#endif
