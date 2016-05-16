#ifndef MOVE_H
#define MOVE_H

class Move {

  private:
      char rowStart_;
      char colStart_;
      char rowEnd_;
      char colEnd_;
      char check_;
      char castling_;
      char enPassant_;
      char enPassantTaken_;

  public:
      explicit Move(char, char, char, char);
      char getRowStart() const;
      char getColStart() const;
      char getRowEnd() const;
      char getColEnd() const;
      void setCheck();
      char getCheck() const;
      void setEnPassant();
      char getEnPassant() const;
      void setEnPassantTaken();
      char getEnPassantTaken() const;
      void setCastling();
      char getCastling() const;

};

#endif
