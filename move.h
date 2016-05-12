#ifndef MOVE_H
#define MOVE_H

class Move {

  private:
      char rowStart_;
      char colStart_;
      char rowEnd_;
      char colEnd_;
      char enPassant_;

  public:
      explicit Move(char, char, char, char);
      char getRowStart() const;
      char getColStart() const;
      char getRowEnd() const;
      char getColEnd() const;
      void setEnPassant();

};

#endif
