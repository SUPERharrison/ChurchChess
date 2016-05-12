#include "knight.h"

char isKnight(char piece) {
    return piece == BLACK_KNIGHT_QUEEN ||
           piece == BLACK_KNIGHT_KING ||
           piece == WHITE_KNIGHT_QUEEN ||
           piece == WHITE_KNIGHT_KING
           ;
}

std::vector<Move> getKnightMoves(const Chessboard& chessboard,
                           char row,
                           char col) {

    if (isKnight(chessboard.get(row, col)) == 0) {
        throw std::invalid_argument("This is not a knight.");
    }

    char color = chessboard.getColor(row, col);

    std::vector<Move> moves;

    char directions[8][2] = {{2, 1}, {2, -1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {1, -2}, {-1, -2}};

    for (int i = 0; i < 8; i++) {
        char rowPrime = row + directions[0];
        char colPrime = col + directions[1];

        if (rowPrime >= 0 && rowPrime <= 7 && colPrime >= 0 && colPrime <= 7 && chessboard.getColor(rowPrime, colPrime) != color) {
            Move m(row, col, rowPrime, colPrime);
            moves.push_back(m);
        }
    }

    return moves;
}
