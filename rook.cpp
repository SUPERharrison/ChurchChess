#include "rook.h"

char isRook(char piece) {
    return piece == BLACK_ROOK_QUEEN  ||
           piece == BLACK_ROOK_KING ||
           piece == WHITE_ROOK_QUEEN ||
           piece == WHITE_ROOK_KING
           ;
}

std::vector<Move> getRookMoves(const Chessboard& chessboard,
                           char row,
                           char col) {

    if (isRook(chessboard.get(row, col)) == 0) {
        throw std::invalid_argument("This is not a rook.");
    }

    std::vector<Move> moves;

    char directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (int i = 0; i < 4; i++) {
        std::vector<Move> m = chessboard.getMovesInDirection(row, col, directions[i][0], directions[i][1]);
        moves.insert(moves.end(), m.begin(), m.end());
    }

    return moves;
}
