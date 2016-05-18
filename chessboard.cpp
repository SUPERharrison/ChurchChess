#include "chessboard.h"

Chessboard::Chessboard() {
    for (char i = 0; i < SQUARE_ON_CHESSBOARD; i++) {
        frame_[i] = OPEN_SQUARE;
    }

    for (char i = 0; i < SQUARE_ON_CHESSBOARD; i++) {
        inCheck_[i] = 0;
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

    whiteKingCastle_ = 1;
    whiteQueenCastle_ = 1;
    blackKingCastle_ = 1;
    blackQueenCastle_ = 1;
    enPassantCol_ = -1;
}

Chessboard::Chessboard(const Chessboard& chessboard) {
    for (char i = 0; i < SQUARE_ON_CHESSBOARD; i++) {
        frame_[i] = chessboard.frame_[i];
    }

    for (char i = 0; i < SQUARE_ON_CHESSBOARD; i++) {
        inCheck_[i] = chessboard.nextInCheck_[i];
    }

    for (char i = 0; i < SQUARE_ON_CHESSBOARD; i++) {
        nextInCheck_[i] = 0;
    }

    enPassantCol_ = chessboard.enPassantCol_;
    whiteKingCastle_ = chessboard.whiteKingCastle_;
    whiteQueenCastle_ = chessboard.whiteQueenCastle_;
    blackKingCastle_ = chessboard.blackKingCastle_;
    blackQueenCastle_ = chessboard.blackQueenCastle_;
}

std::vector<Move> Chessboard::getMoves(char color) {
    std::vector<Move> moves;

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            char piece = get(row, col);
            char pieceColor = getColor(row, col);
            std::vector<Move> m;

            if (pieceColor == color) {
                if (isPawn(piece)) {
                    m = getPawnMoves(*this, row, col);
                }

                if (isKnight(piece)) {
                    m = getKnightMoves(*this, row, col);
                }

                if (isBishop(piece)) {
                    m = getBishopMoves(*this, row, col);
                }

                if (isRook(piece)) {
                    m = getRookMoves(*this, row, col);
                }

                if (isQueen(piece)) {
                    m = getQueenMoves(*this, row, col);
                }

                if (isKing(piece)) {
                    m = getKingMoves(*this, row, col);
                }

                moves.insert(moves.end(), m.begin(), m.end());
            }
        }
    }

    buildNextCheckBoard(moves);

    return moves;
}

void Chessboard::buildNextCheckBoard(const std::vector<Move>& moves) {
    for (int i = 0; i < moves.size(); i++) {
        if (moves[i].getCheck()) {
            char row = moves[i].getRowEnd();
            char col = moves[i].getColEnd();
            char square = row * 8 + col;
            nextInCheck_[square] = 1;
        }
    }
}

Chessboard Chessboard::applyMove(const Move& move) const {
    Chessboard next(*this);
    
    // In every circumstance, we move a piece from one location to another.
    char rowStart = move.getRowStart();
    char colStart = move.getColStart();
    char rowEnd = move.getRowEnd();
    char colEnd = move.getColEnd();

    char pieceStart = next.get(rowStart, colStart);
    char pieceColor = next.getColor(rowStart, colStart);

    if (pieceStart == OPEN_SQUARE) {
        throw std::invalid_argument("Can't move from open square.");
    }

    next.set(rowStart, colStart, OPEN_SQUARE); 
    next.set(rowEnd, colEnd, pieceStart); 

    // We handle the en passant.
    if (move.getEnPassantTaken()) {
        if (pieceColor == WHITE_PIECE) {
            next.set(4, colEnd, OPEN_SQUARE);
        }

        if (pieceColor == BLACK_PIECE) {
            next.set(3, colEnd, OPEN_SQUARE);
        }
    }

    // We always update enPassantCol_ to move.getEnPassant()
    next.enPassantCol_ = move.getEnPassant();

    // We handle castling.
    if (move.getCastling()) {
        if (rowEnd == 0 && colEnd == 2) {
            next.set(rowEnd, 0, OPEN_SQUARE); 
            next.set(rowEnd, 3, WHITE_ROOK_QUEEN); 
        }
        else if (rowEnd == 0 && colEnd == 6) {
            next.set(rowEnd, 0, OPEN_SQUARE); 
            next.set(rowEnd, 5, WHITE_ROOK_KING); 
        }
        else if (rowEnd == 7 && colEnd == 2) {
            next.set(rowEnd, 0, OPEN_SQUARE); 
            next.set(rowEnd, 3, BLACK_ROOK_QUEEN); 
        }
        else if (rowEnd == 7 && colEnd == 6) {
            next.set(rowEnd, 0, OPEN_SQUARE); 
            next.set(rowEnd, 5, BLACK_ROOK_KING); 
        }
        else {
            throw std::invalid_argument("Castling was not properly set.");
        }
    }

    return next;
}

void Chessboard::checkForValidRow(char row) const {
    if (row < 0 || row >= 8) {
        int rowInt = row;
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

void Chessboard::set(char row, char col, char piece) {
    frame_[row * 8 + col] = piece;
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
        m.setCheck();
        moves.push_back(m);
    }

    if (i >= 0 && i <= 7 && j >= 0 && j <= 7 && getColor(i, j) != color) {
        Move m(row, col, i, j);
        m.setCheck();
        moves.push_back(m);
    }

    return moves;
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
