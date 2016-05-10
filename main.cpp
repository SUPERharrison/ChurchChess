#include <iostream>
#include "piece.h"
#include "move.h"

int main(int argc, char** argv) {
    std::cout << "Hello, world!" << std::endl;
    Piece a("name");
    Move b;
    std::cout << b.getX() << std::endl;
    return 0;
}
