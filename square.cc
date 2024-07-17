#include "square.h"

Piece &Square::getPiece() {
    return piece;
}

std::vector<int> Square::getCoords() {
    std::vector<int> v = {x, y};
    return v;
}