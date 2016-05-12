#include "chessboard.h"

Chessboard::Chessboard(char* inCheck) {
    for (char i = 0; i < SQUARE_ON_CHESSBOARD; i++) {
        frame_[i] = OPEN_SQUARE;
    }

    for (char i = 0; i < SQUARE_ON_CHESSBOARD; i++) {
        inCheck_[i] = inCheck[i];
    }

    frame_[0] = WHITE_ROOK_QUEEN;
    frame_[1] = WHITE_KNIGHT_QUEEN;
    frame_[2] = WHITE_BISHOP_QUEEN;
    frame_[3] = WHITE_QUEEN;
    frame_[4] = WHITE_KING;
    frame_[5] = WHITE_BISHOP_KING;
    frame_[6] = WHITE_KNIGHT_KING;
    frame_[7] = WHITE_ROOK_KING;
    frame_[8] = WHITE_PAWN1;
    frame_[9] = WHITE_PAWN2;
    frame_[10] = WHITE_PAWN3;
    frame_[11] = WHITE_PAWN4;
    frame_[12] = WHITE_PAWN5;
    frame_[13] = WHITE_PAWN6;
    frame_[14] = WHITE_PAWN7;
    frame_[15] = WHITE_PAWN8;

    frame_[48] = BLACK_PAWN8;
    frame_[49] = BLACK_PAWN7;
    frame_[50] = BLACK_PAWN6;
    frame_[51] = BLACK_PAWN5;
    frame_[52] = BLACK_PAWN4;
    frame_[53] = BLACK_PAWN3;
    frame_[54] = BLACK_PAWN2;
    frame_[55] = BLACK_PAWN1;
    frame_[56] = BLACK_ROOK_QUEEN;
    frame_[57] = BLACK_KNIGHT_QUEEN;
    frame_[58] = BLACK_BISHOP_QUEEN;
    frame_[59] = BLACK_QUEEN;
    frame_[60] = BLACK_KING;
    frame_[61] = BLACK_BISHOP_KING;
    frame_[62] = BLACK_KNIGHT_KING;
    frame_[63] = BLACK_ROOK_KING;

    enPassantCol_ = -1;
    whiteKingCastle_ = 1;
    whiteQueenCastle_ = 1;
    blackKingCastle_ = 1;
    blackQueenCastle_ = 1;
}

void Chessboard::clearNextCheck() {
    for (char i = 0; i < SQUARE_ON_CHESSBOARD; i++) {
        nextInCheck_[i] = 0;
    }
}

std::vector<Move> Chessboard::getMoves() const {
    std::vector<Move> v;
    return v;
}

void Chessboard::buildNextCheckBoard() const {
    clearNextCheck();
    getMoves();
}

void Chessboard::checkForValidRow(char row) const {
    if (row < 0 || row >= 8) {
        throw std::invalid_argument("Invalid row.");
    }
}

void Chessboard::checkForValidCol(char col) const {
    if (col < 0 || col >= 8) {
        throw std::invalid_argument("Invalid col.");
    }
}

char Chessboard::isBlack(char row, char col) const {
    checkForValidRow(row);
    checkForValidCol(col);
    char piece = get(row, col);

    return piece == BLACK_ROOK_QUEEN ||
           piece == BLACK_KNIGHT_QUEEN ||
           piece == BLACK_BISHOP_QUEEN ||
           piece == BLACK_QUEEN ||
           piece == BLACK_KING ||
           piece == BLACK_BISHOP_KING ||
           piece == BLACK_KNIGHT_KING ||
           piece == BLACK_ROOK_KING ||
           piece == BLACK_PAWN1 ||
           piece == BLACK_PAWN2 ||
           piece == BLACK_PAWN3 ||
           piece == BLACK_PAWN4 ||
           piece == BLACK_PAWN5 ||
           piece == BLACK_PAWN6 ||
           piece == BLACK_PAWN7 ||
           piece == BLACK_PAWN8
           ;
}

char Chessboard::isWhite(char row, char col) const {
    checkForValidRow(row);
    checkForValidCol(col);
    char piece = get(row, col);

    return piece == WHITE_ROOK_QUEEN ||
           piece == WHITE_KNIGHT_QUEEN ||
           piece == WHITE_BISHOP_QUEEN ||
           piece == WHITE_QUEEN ||
           piece == WHITE_KING ||
           piece == WHITE_BISHOP_KING ||
           piece == WHITE_KNIGHT_KING ||
           piece == WHITE_ROOK_KING ||
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

char Chessboard::getColor(char row, char col) const {
    checkForValidRow(row);
    checkForValidCol(col);

    if (isWhite(row, col)) {
        return WHITE_PIECE;
    }

    if (isBlack(row, col)) {
        return BLACK_PIECE;
    }

    return OPEN_SQUARE;
}

char Chessboard::get(char row, char col) const {
    checkForValidRow(row);
    checkForValidCol(col);

    return frame_[row * 8 + col];
}

char Chessboard::setCheck(char row, char col) {
    checkForValidRow(row);
    checkForValidCol(col);

    nextInCheck_[row * 8 + col] = 1;
}

char Chessboard::getCheck(char row, char col) const {
    checkForValidRow(row);
    checkForValidCol(col);

    return inCheck_[row * 8 + col];
}

std::vector<Move> Chessboard::getMovesInDirection(char row, char col, char rowDirection, char colDirection) const {
    checkForValidRow(row);
    checkForValidCol(col);

    char color = getColor(row, col);

    std::vector<Move> moves;

    char i = row + rowDirection;
    char j = col + colDirection;
    for (; i >= 0 && i <= 7 && j >= 0 && j <= 7 && get(i, j) == OPEN_SQUARE; i += rowDirection, j += colDirection) {
        Move m(row, col, i, j);
        setCheck(i, j);
        moves.push_back(m);
    }

    if (i >= 0 && i <= 7 && j >= 0 && j <= 7 && getColor(i, j) != color) {
        Move m(row, col, i, j);
        moves.push_back(m);
    }

    return moves;
}

void Chessboard::resetEnPassantCol() {
    enPassantCol_ = -1;
}

void Chessboard::setEnPassantCol(char col) {
    checkForValidCol(col);
    enPassantCol_ = col;
}

char Chessboard::getEnPassantCol() const {
    return enPassantCol_;
}

char Chessboard::isWhiteKingCastlingAllowed() const {
    return whiteKingCastle_;
}

char Chessboard::isWhiteQueenCastlingAllowed() const {
    return whiteQueenCastle_;
}

char Chessboard::isBlackKingCastlingAllowed() const {
    return blackKingCastle_;
}

char Chessboard::isBlackQueenCastlingAllowed() const {
    return blackQueenCastle_;
}
