#include "square.h"

Square::Square(int x, int y, Piece* piece): x{x}, y{y}, piece{piece} {}

Piece* Square::getPiece() {
    return piece;
}

void Square::setPiece(Piece* piece) {
    this->piece = piece; 
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