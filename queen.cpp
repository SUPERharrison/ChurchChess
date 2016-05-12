#include "queen.h"

char isQueen(char piece) {
    return piece == BLACK_QUEEN ||
           piece == WHITE_QUEEN;
}

std::vector<Move> getQueenMoves(const Chessboard& chessboard,
                           char row,
                           char col) {

    if (isQueen(chessboard.get(row, col)) == 0) {
        throw std::invalid_argument("This is not a queen.");
    }

    std::vector<Move> moves;

    char directions[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

    for (int i = 0; i < 8; i++) {
        std::vector<Move> m = chessboard.getMovesInDirection(row, col, directions[i][0], directions[i][1]);
        moves.insert(moves.end(), m.begin(), m.end());
    }

    return moves;
}
