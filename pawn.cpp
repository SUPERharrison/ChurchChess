#include "pawn.h"

char isPawn(char piece) {
    return piece == BLACK_PAWN1 ||
           piece == BLACK_PAWN2 ||
           piece == BLACK_PAWN3 ||
           piece == BLACK_PAWN4 ||
           piece == BLACK_PAWN5 ||
           piece == BLACK_PAWN6 ||
           piece == BLACK_PAWN7 ||
           piece == BLACK_PAWN8 ||
           piece == WHITE_PAWN1 ||
           piece == WHITE_PAWN2 ||
           piece == WHITE_PAWN3 ||
           piece == WHITE_PAWN4 ||
           piece == WHITE_PAWN5 ||
           piece == WHITE_PAWN6 ||
           piece == WHITE_PAWN7 ||
           piece == WHITE_PAWN8
           ;
}

std::vector<Move> getPawnMoves(const Chessboard& chessboard,
                           char row,
                           char col) {

    if (isPawn(chessboard.get(row, col)) == 0) {
        throw std::invalid_argument("This is not a pawn.");
    }

    char color = chessboard.getColor(row, col);

    std::vector<Move> moves;

    if (color == WHITE_PIECE) {
        if (row < 7 && chessboard.get(row+1, col) == OPEN_SQUARE) {
            Move m(row, col, row+1, col);
            moves.push_back(m);
        }

        if (row == 1 && chessboard.get(2, col) == OPEN_SQUARE && chessboard.get(3, col) == OPEN_SQUARE) {
            Move m(row, col, 3, col);
            m.setEnPassant();
            moves.push_back(m);
        }

        if (row < 7 && col > 0 && chessboard.getColor(row+1, col-1) == BLACK_PIECE) {
            Move m(row, col, row+1, col-1);
            m.setCheck();
            moves.push_back(m);
        }

        if (row < 7 && col < 7 && chessboard.getColor(row+1, col+1) == BLACK_PIECE) {
            Move m(row, col, row+1, col+1);
            m.setCheck();
            moves.push_back(m);
        }

        if (row == 5 && chessboard.getEnPassantCol() == col+1) {
            Move m(row, col, row+1, col+1);
            m.setEnPassantTaken();
            moves.push_back(m);
        }

        if (row == 5 && chessboard.getEnPassantCol() == col-1) {
            Move m(row, col, row+1, col-1);
            m.setEnPassantTaken();
            moves.push_back(m);
        }
    }

    if (color == BLACK_PIECE) {
        if (row > 0 && chessboard.get(row-1, col) == OPEN_SQUARE) {
            Move m(row, col, row-1, col);
            moves.push_back(m);
        }

        if (row == 6 && chessboard.get(5, col) == OPEN_SQUARE && chessboard.get(4, col) == OPEN_SQUARE) {
            Move m(row, col, 4, col);
            m.setEnPassant();
            moves.push_back(m);
        }

        if (row > 0 && col > 0 && chessboard.getColor(row-1, col-1) == WHITE_PIECE) {
            Move m(row, col, row-1, col-1);
            m.setCheck();
            moves.push_back(m);
        }

        if (row > 0 && col < 7 && chessboard.getColor(row-1, col+1) == WHITE_PIECE) {
            Move m(row, col, row-1, col+1);
            m.setCheck();
            moves.push_back(m);
        }

        if (row == 4 && chessboard.getEnPassantCol() == col+1) {
            Move m(row, col, row+1, col+1);
            m.setEnPassantTaken();
            moves.push_back(m);
        }

        if (row == 4 && chessboard.getEnPassantCol() == col+1) {
            Move m(row, col, row+1, col+1);
            m.setEnPassantTaken();
            moves.push_back(m);
        }
    }

    return moves;
}
