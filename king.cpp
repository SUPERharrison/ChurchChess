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
        if (chessboard.getColor(rowPrime, colPrime) != color && chessboard.getCheck(rowPrime, colPrime) == 0) {
            Move m(row, col, rowPrime, colPrime);
            m.setCheck();
            moves.push_back(m);
        }
    }

    // Castling
    if (color == WHITE_PIECE && chessboard.isWhiteKingCastlingAllowed()) {
        if (chessboard.get(row, 5) == OPEN_SQUARE &&
            chessboard.get(row, 6) == OPEN_SQUARE &&
            chessboard.getCheck(row, 5) == 0 &&
            chessboard.getCheck(row, 6) == 0) {
            Move m(row, col, row, 6);
            m.setCastling();
            moves.push_back(m);
        }
    }

    if (color == WHITE_PIECE && chessboard.isWhiteQueenCastlingAllowed()) {
        if (chessboard.get(row, 2) == OPEN_SQUARE &&
            chessboard.get(row, 3) == OPEN_SQUARE &&
            chessboard.getCheck(row, 2) == 0 &&
            chessboard.getCheck(row, 3) == 0) {
            Move m(row, col, row, 2);
            m.setCastling();
            moves.push_back(m);
        }
    }

    if (color == BLACK_PIECE && chessboard.isBlackKingCastlingAllowed()) {
        if (chessboard.get(row, 5) == OPEN_SQUARE &&
            chessboard.get(row, 6) == OPEN_SQUARE &&
            chessboard.getCheck(row, 5) == 0 &&
            chessboard.getCheck(row, 6) == 0) {
            Move m(row, col, row, 6);
            m.setCastling();
            moves.push_back(m);
        }
    }

    if (color == BLACK_PIECE && chessboard.isBlackQueenCastlingAllowed()) {
        if (chessboard.get(row, 2) == OPEN_SQUARE &&
            chessboard.get(row, 3) == OPEN_SQUARE &&
            chessboard.getCheck(row, 2) == 0 &&
            chessboard.getCheck(row, 3) == 0) {
            Move m(row, col, row, 2);
            m.setCastling();
            moves.push_back(m);
        }
    }

    return moves;
}
