#include "bishop.h"

char isBishop(char piece) {
    return piece == BLACK_BISHOP_QUEEN ||
           piece == BLACK_BISHOP_KING ||
           piece == WHITE_BISHOP_QUEEN ||
           piece == WHITE_BISHOP_KING
           ;
}

std::vector<Move> getBishopMoves(const Chessboard& chessboard,
                           char row,
                           char col) {

    if (isBishop(chessboard.get(row, col)) == 0) {
        throw std::invalid_argument("This is not a bishop.");
    }

    std::vector<Move> moves;

    char directions[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

    for (int i = 0; i < 4; i++) {
        std::vector<Move> m = chessboard.getMovesInDirection(row, col, directions[i][0], directions[i][1]);
        moves.insert(moves.end(), m.begin(), m.end());
    }

    return moves;
}
