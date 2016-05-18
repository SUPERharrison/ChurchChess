#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <stdexcept>
#include <vector>
#include "move.h"

#define SQUARE_ON_CHESSBOARD 64

#define OPEN_SQUARE 0
#define WHITE_PIECE 1
#define BLACK_PIECE 2

#define WHITE_ROOK_QUEEN 1
#define WHITE_KNIGHT_QUEEN 2
#define WHITE_BISHOP_QUEEN 3
#define WHITE_QUEEN 4
#define WHITE_KING 5
#define WHITE_BISHOP_KING 6
#define WHITE_KNIGHT_KING 7
#define WHITE_ROOK_KING 8
#define WHITE_PAWN1 9
#define WHITE_PAWN2 10
#define WHITE_PAWN3 11
#define WHITE_PAWN4 12
#define WHITE_PAWN5 13
#define WHITE_PAWN6 14
#define WHITE_PAWN7 15
#define WHITE_PAWN8 16

#define BLACK_ROOK_QUEEN 17
#define BLACK_KNIGHT_QUEEN 18
#define BLACK_BISHOP_QUEEN 19
#define BLACK_QUEEN 20
#define BLACK_KING 21
#define BLACK_BISHOP_KING 22
#define BLACK_KNIGHT_KING 23
#define BLACK_ROOK_KING 24
#define BLACK_PAWN1 25
#define BLACK_PAWN2 26
#define BLACK_PAWN3 27
#define BLACK_PAWN4 28
#define BLACK_PAWN5 29
#define BLACK_PAWN6 30
#define BLACK_PAWN7 31
#define BLACK_PAWN8 32

class Chessboard {

    private:
        char frame_[SQUARE_ON_CHESSBOARD]; 
        unsigned long inCheck_; 
        char enPassantCol_;
        char whiteKingCastle_;
        char whiteQueenCastle_;
        char blackKingCastle_;
        char blackQueenCastle_;

        void set(char, char, char);
        char isKingInCheck(char);
        void buildCheckBoard(const std::vector<Move>&);
        void checkForValidRow(char) const;
        void checkForValidCol(char) const;

    public:
        Chessboard();
        Chessboard(const Chessboard&);
        std::vector<Move> getMoves(char);
        Chessboard applyMove(const Move&) const;
        char isBlack(char, char) const;
        char isWhite(char, char) const;
        char getColor(char, char) const;
        char get(char, char) const;
        char getCheck(char, char) const;
        char getEnPassantCol() const;
        std::vector<Move> getMovesInDirection(char, char, char, char) const;

        char isWhiteKingCastlingAllowed() const;
        char isWhiteQueenCastlingAllowed() const;
        char isBlackKingCastlingAllowed() const;
        char isBlackQueenCastlingAllowed() const;
};

#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "rook.h"
#include "queen.h"
#include "king.h"

#endif
