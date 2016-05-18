#include <iostream>
#include <vector>
#include "chessboard.h"

using namespace std;

int main(int argc, char** argv) {
    cout << "Hello, world!" << std::endl;
    Chessboard c;
    vector<Move> moves = c.getMoves(WHITE_PIECE);

    for (int i = 0; i < moves.size(); i++) {
        moves[i].print();
    }

    Chessboard cPrime = c.applyMove(moves[12]);
    vector<Move> movesPrime = cPrime.getMoves(WHITE_PIECE);

    cout << "--------------"  << endl;
    for (int i = 0; i < movesPrime.size(); i++) {
        movesPrime[i].print();
    }
    return 0;
}
