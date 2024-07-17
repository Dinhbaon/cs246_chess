#include "square.h"

Piece* Square::getPiece() {
    return piece;
}

std::vector<int> Square::getCoords() {
    std::vector<int> v = {x, y};
    return v;
}

int Square::getX() const {
    return x; 
}

int Square::getY() const {
    return y; 
}

bool Square::isEmpty() const {
    return piece == nullptr; 
}