#include "king.h"

char isKing(char piece) {
    return piece == BLACK_KING ||
           piece == WHITE_KING;
}

std::vector<Move> getKingMoves(const Chessboard& chessboard,
                           char row,
                           char col) {

    if (isKing(chessboard.get(row, col)) == 0) {
        throw std::invalid_argument("This is not a king.");
    }

    std::vector<Move> moves;
    char color = chessboard.getColor(row, col);

    char directions[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

    // Regular moves
    for (int i = 0; i < 8; i++) {
        char rowPrime = row + directions[i][0];
        char colPrime = col + directions[i][1];
        if (chessboard.getColor(rowPrime, colPrime) != color) {
            Move m(row, col, rowPrime, colPrime);
            moves.push_back(m);
        }
    }

    // Castling
    if (color == WHITE_PIECE && chessboard.isWhiteKingCastlingAllowed()) {
        if (chessboard.get(0, 5) == OPEN_SQUARE && chessboard.get(0, 6) == OPEN_SQUARE) {
            Move m(row, col, row, 6);
            m.setCastling();
            moves.push_back(m);
        }
    }

    return moves;
}
