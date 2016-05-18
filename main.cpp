#include <iostream>
#include <vector>
#include "chessboard.h"

using namespace std;

int main(int argc, char** argv) {
    cout << "Hello, world!" << std::endl;
    Chessboard c;
    vector<Move> moves = c.getMoves(BLACK_PIECE);

    for (int i = 0; i < moves.size(); i++) {
        moves[i].print();
    }

    return 0;
}
